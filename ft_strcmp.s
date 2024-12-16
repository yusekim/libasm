global _ft_strcmp
section .text

_ft_strcmp:
	xor rax, rax ; rax내 값을 0으로 초기화

loop_start:
	mov dl, [rdi]
	mov dh, [rsi]
	cmp dl, dh
	jne loop_end ; jne: jump if not equal, if (*s1 != *s2)
	cmp dl, 0
	je loop_end ; if (*s1 == 0)
	inc rdi ; s1++
	inc rsi ; s2++
	jmp loop_start

loop_end:
	sub dl, dh
	movsx rax, dl ; ret = *s1 - *s2
	ret
