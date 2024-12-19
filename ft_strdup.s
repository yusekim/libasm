global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern ___error
extern _malloc
section .text

_ft_strdup:
;	mov rdx, rdi		; 기존 코드(오류남)
	push rdi			; 인자로 들어온 주솟값(s1) 저장
	call _ft_strlen
	mov rdi, rax		; _ft_strlen 결괏값을 malloc의 인자로
	inc rdi				; rdi + 1 for null-terminator
	call _malloc
	jc error_handle		; carry bit if its on, then jump
	pop rsi				; _ft_strcpy의 두 번째 인자 (srcs) 설정
	mov rdi, rax		; _ft_strcpy의 첫 번째 인자 (dest) 설정
	push rdx
	call _ft_strcpy
	pop rdx
	ret

error_handle:
	mov rdx, rax		; rax에 저장된 에러 코드 저장
	call ___error		; errno 변수가 저장되는 주소 불러오기
	mov [rax], rdx		; store error code in errno
	xor rax, rax		; return 0(nullptr)
	pop rdi
	ret
