global _ft_list_size
section .text

_ft_list_size:
	xor rax, rax ; int len = 0

loop_start:
	cmp rdi, 0
	je loop_end
	inc rax
	mov rdx, [rdi + 8]
	mov rdi, rdx
	jmp loop_start

loop_end:
	ret
