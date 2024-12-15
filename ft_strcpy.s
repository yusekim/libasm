global _ft_strcpy
section .text

_ft_strcpy:

loop_start:
	mov dl, [rsi]
	mov [rdi], dl ; *dst = *src
	cmp dl, 0 ; if *dst == 0
	je loop_end
	inc rsi ; rsi++
	inc rdi ; rdi++
	jmp loop_start

loop_end:
	ret
