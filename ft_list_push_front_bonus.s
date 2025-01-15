global _ft_list_push_front
extern _malloc
extern ___error
section .text

;void ft_list_push_front(t_list **begin_list, void *data);

_ft_list_push_front:
	cmp rdi, 0
	je return
	push rdi			; 매개변수 (**begin_list) 스택에 저장
	push rsi			; 매개변수(*data) 스택에 저장


; =============== making new node ===============
	mov rdi, 16			; 노드 한 개의 크기(16byte)설정
	push rdx			 ; stack alignment
	call _malloc
	jc error_handle		; malloc fail handler
	pop rdx				; stack alignment pop
; ============ making new node done =============

	pop rsi				; 매개변수(*data) 다시 불러오기
	mov [rax], rsi		; 새 노드의 *data 섹션에 매개변수로 가져온 *data 넣기
	add rax, 8			; 새 노드의 next
	pop rdi				; 매개변수 (**begin_list) 다시 불러오기
	mov rdx, qword[rdi] ; 매개변수 (**begin_list) 를 rdx에 저장
	mov [rax], rdx		; 새 노드의 next를 begin_list의 주솟값으로 설정하기
	sub rax, 8
	mov [rdi], rax
	jmp return

error_handle:
	mov rdx, rax		; rax에 저장된 errno 저장
	call ___error		; errno 변수가 저장되는 주소 불러오기
	mov [rax], rdx		; store errno
	pop rdx
	pop rsi
	pop rdi

return:
	xor rax, rax		; return 0
	ret
