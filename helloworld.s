section .data
    message db "Hello, World!", 0xA ; 문자열 데이터 (개행 문자 포함)
    message_len equ $ - message     ; 문자열 길이 계산

section .text
    global _start                   ; 링커가 찾을 진입점 정의

_start:
    ; 시스템 호출: write
    mov rax, 0x2000004              ; 시스템 호출 번호: write (macOS)
    mov rdi, 1                      ; 파일 디스크립터: 표준 출력(stdout)
    lea rsi, [rel message]          ; 출력할 문자열 주소
    mov rdx, message_len            ; 출력할 문자열 길이
    syscall                         ; 시스템 호출 실행

    ; 시스템 호출: exit
    mov rax, 0x2000001              ; 시스템 호출 번호: exit (macOS)
    xor rdi, rdi                    ; 종료 코드: 0
    syscall                         ; 시스템 호출 실행
