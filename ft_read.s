global _ft_read
extern ___error
section .text

_ft_read:
	mov rax, 0x2000003		; syscall number set to _ft_read
	push rdx				; stack alignment
	syscall					; syscall read
	jc error_handle			; if syscall failed, then jump
	pop rdx
	ret

error_handle:
	mov rdx, rax				; rax 에 저장된 에러 코드 저장
	call ___error			; errno 주소 가져오기
	mov [rax], rdx			; store error code in errno
	mov rax, -1				; -1 return
	pop rdx
	ret
