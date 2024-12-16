global _ft_strlen
section .text

_ft_strlen:
	xor rax, rax ; int len = 0

loop_start: ; 반복문 시작
	mov dl, [rdi] ; scratch register 중 하나인 rdx(8바이트)중 1바이트 부분인 dl에 데이터 mov
	cmp dl, 0 ; *str == 0
	je loop_end ; je jump if equal
	inc rax ; len++
	inc rdi ; str++
	jmp loop_start

loop_end:
	ret
