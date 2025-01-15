global _ft_list_remove_if
extern _free
section .text

;void ft_list_remove_if(t_list **begin_list,
					;	void *data_ref,
					;	int (*cmp)(void *, void *),
					;	void (*free_fct)(void *))


; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *))
; {
; 	t_list	*current;
; 	t_list	*temp;

; 	if (!begin_list || !*begin_list)
; 		return ;
; 	while (*begin_list)
; 	{
; 		if (cmp((*begin_list)->data, data_ref) == 0)
; 		{
; 			temp = *begin_list;
; 			*begin_list = (*begin_list)->next;
; 			free_fct(temp->data);
; 			free(temp);
; 		}
; 		else
; 		{
; 			current = *begin_list;
; 			begin_list = &current->next;
; 		}
; 	}
; }

_ft_list_remove_if:
	cmp rdi, 0
	je return
	mov r8, [rdi]									; r8에 *begin_list 저장
	cmp r8, 0
	je return
	cmp rsi, 0
	je return
	cmp rdx, 0
	je return
	cmp rcx, 0
	je return
; =============== 예외처리 ===============
	mov rax, rdx								; rax에 (cmp())저장
	mov rdx, rdi								; rdx에 **begin_list 저장
list_traverse:
	cmp r8, 0									; while (*begin_list)
	je return
	mov rdi, [r8]								; rdi에 (*begin_list)->data 저장
	push rax
	push rsi
	push rdx
	push rcx
	push r8
	call rax
	pop r8
	pop rcx
	pop rdx
	cmp rax, 0
	je free_node
	lea rdx, [r8 + 8]
	mov r8, [rdx]

after_free:
	pop rsi
	pop rax
	jmp list_traverse

free_node:
	mov r9, [r8 + 8]							; r9에 cur_node->next저장
	mov [rdx], r9								; *begin_list = cur_node->next
	mov rdi, [r8]								; rdi에 cur_node->data 저장
	mov rax, rcx								; rax에 free_fct저장
	push rcx
	push rdx
	push r8
	call rax									; free_fct 호출
	pop r8
	mov rdi, r8									; rdi에 r8(cur_node) 저장
	push r8										; stack alignment
	call _free
	pop r8
	pop rdx
	pop rcx
	mov r8, [rdx]
	jmp after_free

return:
	xor rax, rax								; return 0
	ret
