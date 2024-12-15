global _ft_read
extern ___error
section .text

_ft_read:
	mov rax, 0x2000003 ; syscall number set to _ft_read
	syscall ; call read
	jc error_handle ; if syscall failed, then jump
	ret

error_handle:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx ; store error code in errno
	mov rax, -1
	ret
