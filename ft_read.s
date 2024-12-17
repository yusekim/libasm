global _ft_read
extern ___error
section .text

_ft_read:
	mov rax, 0x2000003		; syscall number set to read
	syscall					; syscall read
	jc error_handle			; if syscall failed, then jump
	ret

error_handle:
	push rax
	call ___error			; errno 주소 가져오기
	pop qword [rax]			; store error code in errno
	mov rax, -1				; -1 return
	ret
