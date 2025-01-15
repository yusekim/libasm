global _ft_list_sort
section .text

; void    ft_list_sort(t_list **begin_list, int (*cmp)())
; {
;     int     swapped;
;     t_list  *current;
;     t_list  *last;

;     if (!begin_list || !*begin_list)
;         return ;
;     last = NULL;
;     swapped = 1;
;     while (swapped)
;     {
;         swapped = 0;
;         current = *begin_list;
;         while (current->next != last)
;         {
;             if (cmp(current->data, current->next->data) > 0)
;             {
;                 void *temp = current->data;
;                 current->data = current->next->data;
;                 current->next->data = temp;
;                 swapped = 1;
;             }
;             current = current->next;
;         }
;         last = current;
;     }
; }


_ft_list_sort:
	cmp rdi, 0
	je return
	mov rdi, [rdi]									; rdi에 *begin_list 저장
	cmp rdi, 0
	je return
	cmp rsi, 0
	je return
; =============== 예외처리 ===============
	mov rax, rsi									; rax에 (*cmp)() 저장
	xor rdx, rdx									; rdx 0(NULL)초기화
	mov r8, rdi										; r8에 *begin_list 저장
	mov rcx, r8										; rcx에 *begin_list 저장
	xor r10, r10									; swapped 0으로 초기화
	jmp bubble_loop

bubble_sort:
	cmp r10, 0										; while (swapped)
	je return
	xor r10, r10									; swapped 0으로 초기화
	mov rdx, rcx									; last(탐색할 범위) 업데이트
	mov rcx, r8										; current를 *begin_list로 재지정

bubble_loop:
	cmp [rcx + 8], rdx								; while (cur_node-> next != last)
	je bubble_sort
	mov rdi, [rcx]									; rdi에 cur_node->data 저장
	push rcx										; 스택에 cur_node 저장
	mov rcx, [rcx + 8]								; rcx에 cur_node->next 저장
	mov rsi, [rcx]									; rcx에 next_node->data 저장
	pop rcx											; rcx에 cur_node 복원
	push rax
	push rdx
	push r8
	push rcx
	push r10
	push rsi
	push rdi
	call rax										; (*cmp)() 함수 call
	pop rdi											; cur->data 복원
	pop rsi											; next->data 복원
	pop r10											; swapped 복원
	pop rcx											; rcx에 cur_node 복원
	cmp eax, 0
	jg swap

afterswap:
	pop r8
	pop rdx
	pop rax
	mov rcx, [rcx + 8]								; rcx에 cur_node->next 저장
	jmp bubble_loop

swap:
	mov r11, [rcx + 8]								; r11에 next_node 저장
	mov [r11], rdi									; next->data에 cur->data저장
	mov [rcx], rsi									; cur->data에 next->data저장
	mov r10, 1										; swapped = 1
	jmp afterswap

return:
	xor rax, rax									; return 0
	ret
