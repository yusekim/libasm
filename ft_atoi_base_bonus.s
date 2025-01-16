global _ft_atoi_base
extern _ft_strlen
section .text

_ft_atoi_base:
	push rdi					; 첫번째 매개변수(*str) 스택에 저장

execption_test_1:				; 예외처리 #1. "return 0 if the base is empty or size of 1"
	mov rdi, rsi				; 두번째 매개변수(*base)를 rdi로 mov
	call _ft_strlen				; _ft_strlen 호출
	pop rdi						; 첫번째 매개변수 (*str) 복원
	cmp rax, 1					; if (len <= 1)
	jle invalid_arg				; jle: jump less or equal
	push rsi					; str 주솟값 스택에 저장

execption_test_2:				; 예외처리 #2. "return 0 if the base contains + or - or whitespaces"
	mov dl, [rsi]				; *base 가져오기
	cmp dl, 0
	je execption_test_3			; \0 도달시 다음 테스트로
	cmp dl, 43					; if (*base == '+')
	je pop_before_return
	cmp dl, 45					; if (*base == '-')
	je pop_before_return
	cmp dl, 32					; if (*base == ' ')
	je pop_before_return
	inc rsi						; base + 1
	jmp execption_test_2

execption_test_3:				; 예외처리 #3. "return 0 if the base contains the same character twice"
	pop rsi						; base 복원
	push rsi					; base 다시 스택에 저장
execption_test_3_loop1:
	mov dh, [rsi]				; *base 가져오기
	cmp dh, 0
	je convert					; \0 도달시 테스트 통과
	inc rsi						; base++
	mov r8, rsi					; r8에 rsi 복사
execption_test_3_loop2:
	mov dl, [r8]
	cmp dl, 0
	je execption_test_3_loop1	; \0 도달시 다음 문자에 대해 중복검사
	cmp dh, dl
	je pop_before_return		; 중복 문자 발견시 스택을 비우고 리턴
	inc r8						; r8 에 저장된 주솟값 + 1
	jmp execption_test_3_loop2

convert:
	pop rsi						; base 복원
	mov r11, rax				; rdx에 rax값(strlen(base)) 저장
	mov r10, rsi				; r10에 rsi 값 저장
	xor rax, rax				; rax 0으로 초기화
	mov r8, 1					; r8(sign) 1으로 초기화
	xor r9, r9					; r9(counter) 0으로 초기화
	cmp byte [rdi], 43			; if (*str == '+')
	je is_plus
	cmp byte [rdi], 45			; if (*str == '-')
	je is_minus
	jmp convert_loop1

is_plus:
	inc rdi
	jmp convert_loop1

is_minus:
	mov r8, -1
	inc rdi

convert_loop1:
	mov ch, [rdi]				; ch에 *str담기
	cmp ch, 0
	je return					; \0 도달시 리턴
	cmp ch, 43
	je invalid_arg				; *str 중간에 '-' 출현시 0 반환
	cmp ch, 45
	je invalid_arg				; *str 중간에 '+' 출현시 0 반환
convert_loop2:
	mov cl, [r10]				; cl에 *base담기
	cmp cl, 0					; str내 문자가 base에 없을경우
	je invalid_arg
	cmp ch, cl
	je add_convert				; return_val += counter
	inc r10						; base++
	inc r9						; counter++
	jmp convert_loop2

add_convert:
;	mul rdx 하면 안됨~~!!!!!!!!!!!!!
	mul r11						; rax 값을 mul r11를 통해 자릿수 올림
	add rax, r9					; rax + counter
	xor r9, r9					; counter 0으로 초기화
	inc rdi						; str++
	mov r10, rsi				; r10에 base 첫 문자의 주소 저장
	jmp convert_loop1

pop_before_return:
	pop rsi

invalid_arg:
	xor rax, rax
	ret							; return 0

return:
	mul r8						; sign 맞추기
	ret
