global _ft_strlen
section .text

_ft_strlen:
	xor rax, rax ; int len = 0

loop_start: ; 반복문 시작
	mov dl, [rdi]
	cmp dl, 0 ; *str == 0
	je loop_end
	inc rax ; len++
	inc rdi ; str++
	jmp loop_start

loop_end:
	ret
