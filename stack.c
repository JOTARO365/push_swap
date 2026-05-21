/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** stack.c — Linked list operations สำหรับ stack
**
** Stack นี้ใช้ linked list โดย:
**   - HEAD = TOP of stack (index 0)
**   - TAIL = BOTTOM of stack
**   - node->next ชี้ไปยัง node ที่อยู่ "ลึกกว่า" ใน stack
**
** new_node(val):
**   malloc t_node ใหม่, set val, idx=0, next=NULL
**   คืน pointer หรือ NULL ถ้า malloc ล้มเหลว
**
** stack_push(top, node):
**   เพิ่ม node ที่ TOP (prepend) — เหมือน push ใน stack ทั่วไป
**   O(1)
**
** stack_pop(top):
**   เอา node ออกจาก TOP — เหมือน pop ใน stack ทั่วไป
**   คืน node ที่ pop ออกมา (caller ต้อง free หรือ reuse)
**   O(1)
**
** stack_size(top):
**   นับจำนวน node ใน stack
**   O(n)
**
** stack_free(top):
**   free ทุก node ใน stack, set *top = NULL
*/

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = val;
	node->idx = 0;
	node->next = NULL;
	return (node);
}

void	stack_push(t_node **top, t_node *node)
{
	node->next = *top;
	*top = node;
}

t_node	*stack_pop(t_node **top)
{
	t_node	*node;

	if (!*top)
		return (NULL);
	node = *top;
	*top = node->next;
	node->next = NULL;
	return (node);
}

int	stack_size(t_node *top)
{
	int	size;

	size = 0;
	while (top)
	{
		size++;
		top = top->next;
	}
	return (size);
}

void	stack_free(t_node **top)
{
	t_node	*tmp;

	while (*top)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
}
