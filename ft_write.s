global _ft_write
extern ___error
section .text

_ft_write:
	mov rax, 0x2000004		; syscall number set to write
	syscall					; syscall write
	jc error_handle			; if syscall failed, then jump
	ret

error_handle:
	push rax
	call ___error			; errno 주소 가져오기
	pop qword [rax]			; Store error code in errno
	mov rax, -1				; -1 반환값 저장
	ret
