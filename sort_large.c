/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sort_large.c — Turkish sort สำหรับ n > 5
**
** get_at(stack, pos):
**   คืน pointer ของ node ที่ position pos (0 = top)
**   ใช้ใน insert_from_b เพื่อดึง node ที่ตำแหน่ง best_b_pos
**
** push_all_to_b(ps):
**   ดัน elements จาก a ไป b จนเหลือ 3 elements ใน a
**
** rotate_sorted_top(ps):
**   หลัง insert เสร็จ a เป็น "circularly sorted"
**   หมุน a เพื่อให้ element ที่มี idx=0 ขึ้นมา top
**   เลือก ra หรือ rra ขึ้นอยู่กับทิศที่ถูกกว่า
**
** insert_from_b(ps):
**   ทำซ้ำจนกว่า b จะว่าง:
**   best_b_pos → get_at → find_target → do_move → pa
**
** sort_large(ps):
**   push_all_to_b → sort_3 (3 elements ที่เหลือ)
**   → insert_from_b → rotate_sorted_top
*/

#include "push_swap.h"

static t_node	*get_at(t_node *stack, int pos)
{
	while (pos > 0 && stack)
	{
		stack = stack->next;
		pos--;
	}
	return (stack);
}

static void	push_all_to_b(t_ps *ps)
{
	while (stack_size(ps->a) > 3)
		pb(ps);
}

static void	rotate_sorted_top(t_ps *ps)
{
	int	pos;
	int	size;

	pos = find_min_pos(ps->a);
	size = stack_size(ps->a);
	if (pos <= size / 2)
	{
		while (ps->a->idx != 0)
			ra(ps);
	}
	else
	{
		while (ps->a->idx != 0)
			rra(ps);
	}
}

static void	insert_from_b(t_ps *ps)
{
	int		pos_b;
	int		pos_a;
	t_node	*node;

	while (ps->b)
	{
		pos_b = best_b_pos(ps);
		node = get_at(ps->b, pos_b);
		pos_a = find_target(ps, node->idx);
		do_move(ps, pos_a, pos_b);
	}
}

void	sort_large(t_ps *ps)
{
	push_all_to_b(ps);
	sort_3(ps);
	insert_from_b(ps);
	rotate_sorted_top(ps);
}
