global _ft_write
extern ___error
section .text

_ft_write:
	mov rax, 0x2000004 ; syscall number set to write
	syscall ; call write
	jc error_handle ; if syscall failed, then jump
	ret

error_handle:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx ; Store error num in errno
	mov rax, -1
	ret
