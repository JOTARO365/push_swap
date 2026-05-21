/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ops_rotate.c — Operations: ra, rb, rr
**
** rotate_one(stack):
**   ย้าย TOP node ไปที่ BOTTOM (shift up all by 1)
**   [A: 1→2→3] → ra → [A: 2→3→1]
**   Algorithm:
**     1. เก็บ first = *stack (top node)
**     2. ย้าย head: *stack = first->next
**     3. วน loop หา last node
**     4. ต่อ first ไว้ท้าย: last->next = first
**     5. ตัด first ออกจาก chain เก่า: first->next = NULL
**   ถ้า stack มีน้อยกว่า 2 elements → ไม่ทำอะไร
**
** ra(ps): rotate stack a → print "ra\n"
** rb(ps): rotate stack b → print "rb\n"
** rr(ps): rotate ทั้งสอง stack พร้อมกัน → print "rr\n"
**         สำคัญ: "rr\n" นับเป็น 1 operation แทนที่จะเป็น 2
**         ช่วยลด operation count ได้เมื่อ cost_a และ cost_b ทิศเดียวกัน
*/

#include "push_swap.h"

static void	rotate_one(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_ps *ps)
{
	rotate_one(&ps->a);
	if (!ps->silent)
		write(1, "ra\n", 3);
}

void	rb(t_ps *ps)
{
	rotate_one(&ps->b);
	if (!ps->silent)
		write(1, "rb\n", 3);
}

void	rr(t_ps *ps)
{
	rotate_one(&ps->a);
	rotate_one(&ps->b);
	if (!ps->silent)
		write(1, "rr\n", 3);
}
