global _ft_strcmp
section .text

_ft_strcmp:
	xor rax, rax

loop_start:
	mov dl, [rdi]
	mov dh, [rsi]
	cmp dl, dh
	jne loop_end ; if (*s1 != *s2)
	cmp dl, 0
	je loop_end ; if (*s1 == 0)
	inc rdi ; s1++
	inc rsi ; s2++
	jmp loop_start

loop_end:
	sub dl, dh
	movsx rax, dl ; ret = *s1 - *s2
	ret
