global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern ___error
extern _malloc

_ft_strdup:
	push rdi			; 매개변수(s1)를 stack에 push
	call _ft_strlen
	mov rdi, rax		; _ft_strlen 결괏값을 malloc의 인자로
	inc rdi				; rdi + 1 for \0
	call _malloc
	jc error_handle		; carry bit if its on, then jump
	pop rdx				; rdx = 문자열의 주소(src)
	mov rdi, rax
	mov rsi, rdx
	push rdx
	call _ft_strcpy
	pop rdx
	ret

error_handle:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx ; store error num in errno
	pop rdx
	mov rax, 0
	ret
