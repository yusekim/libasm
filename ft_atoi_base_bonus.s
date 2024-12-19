global _ft_atoi_base
extern _ft_strlen
section .text

; TODO: 자릿수 올라갈 때마다 * strlen 해주기!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1


_ft_atoi_base:
	mov rdx, rsi		; 두번째 매개변수 *base rdx에 저장
	push rdx			; *base 스택에 저장
	push rsi			; 두번째 매개변수 *base 스택에 저장
	push rdi			; 첫번째 매개변수 *str 스택에 저장

execption_test_1:
	mov rdi, rsi		; 두번째 매개변수 *base의 길이를 구하기 위해 rdi 로 mov
	call _ft_strlen		; _ft_strlen 호출 (ft_strlen(base))
	pop rdi				; 첫번째 매개변수 *str rdi 레지스터로 불러오기, 현재 스택에는 rsi(*base)가 남겨져 있음
	cmp rax, 1			; 예외처리 #1, "return 0 if the base is empty or size of 1"
	jle invalid_arg		; jump less or equal

execption_test_2:
	pop rsi				; *base 값을 rsi로 불러오기
	mov al, [rsi]		; int i = 0; str[i] 가져오기
	inc rsi				; rsi(*base) 주솟값 + 1
	push rsi			; base++ 스택에 저장
	cmp al, 43			; if (base[i] == '+')
	je invalid_arg
	cmp al, 45			; if (base[i] == '-')
	je invalid_arg
	cmp al, 32			; if (base[i] == ' ')
	je invalid_arg
	cmp byte [rsi], 0		; 문자열 전부를 테스트 완료했을때 다음 단계로 jump
	je convert

execption_test_loop:
	mov ah, [rsi]		; int j = i + 1; base[j]
	cmp ah, 0
	je execption_test_2 ; al(str[i])에 대해 중복 문자가 base에 없음
	cmp al, ah			; if (base[i] == base[j])
	je invalid_arg		; 예외처리 #2, "return 0 if base contains the same character twice"
	inc rsi
	jmp execption_test_loop

convert:
; rax = strlen(base)
; rdi = *str
; rsi = *base의 \0 -> 쓰레기값
; rdx = ??
; 스택 = *base \0, *base 첫 문자 주소
	xor rax, rax		; rax 0으로 초기화
	xor r9, r9			; r9 0으로 초기화
	pop rdx
	pop rdx				; 스택 내용 클리어, rdx에는 이제 base의 첫 문자 주소가 담겨져 있음
	mov rsi, rdx		; rsi에 base의 첫 문자 주소 담기
	cmp byte [rdi], 43	; if(str[0] == '+')
	je is_plus
	cmp byte [rdi], 45	; if(str[0] == '-')
	je is_minus

convert_loop:
	mov ch, [rdi]		; ch에 *str 담기
	cmp ch, 0			; str 전부 돌았으면 리턴
	je return
	mov cl, [rsi]		; cl에 base[i] 담기
	cmp ch, cl			; if (*str == base[i])
	je add_convert		; return_val += i
	inc rsi				; base++
	inc r9				; i++
	jmp convert_loop

is_plus:
	mov r8, 1
is_minus:
	mov r8, -1
	inc rdi
	jmp convert_loop

add_convert:
	add rax, r9
	xor r9, r9			; r9 0으로 초기화
	inc rdi
	mov rsi, rdx		; rsi에 base의 첫 문자 주소 담기
	jmp convert_loop

invalid_arg:
	pop rsi
	pop rdx
	xor rax, rax
	ret					; return 0

return:
	mul r8			; 부호 맞추기
	ret
