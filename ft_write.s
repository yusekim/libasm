global _ft_write
extern ___error
section .text

_ft_write:
	mov rax, 0x2000004		; syscall number set to write
	push rdx				; stack alignment
	syscall					; call write
	jc error_handle			; if syscall failed, then jump
	pop rdx
	ret

error_handle:
	mov rdx, rax			; rax 에 저장된 에러 코드 저장
	call ___error			; errno 주소 가져오기
	mov [rax], rdx			; Store error code in errno
	mov rax, -1				; -1 반환값 저장
	pop rdx
	ret
