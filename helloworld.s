section .data
    msg db "Hello, World!", 0xA     ; 출력할 문자열과 줄바꿈 문자
    len equ $ - msg                 ; 문자열 길이 계산 (현재 주소 - msg 시작 주소)

section .text
    global _start                   ; 엔트리 포인트 정의

_start:
    ; write 시스템 호출
    mov rax, 0x2000004              ; syscall 번호: write
    mov rdi, 1                      ; 파일 디스크립터: stdout
    lea rsi, [rel msg]              ; 출력할 문자열 주소 (relocation-safe 방식)
    mov rdx, len                    ; 문자열 길이
    syscall                         ; 시스템 호출 실행

    ; exit 시스템 호출
    mov rax, 0x2000001              ; syscall 번호: exit
    xor rdi, rdi                    ; 반환 코드 0 (exit(0))
    syscall                         ; 시스템 호출 실행
