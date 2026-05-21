/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ops_rrotate.c — Operations: rra, rrb, rrr
**
** rrotate_one(stack):
**   ย้าย BOTTOM node ไปที่ TOP (shift down all by 1)
**   [A: 1→2→3] → rra → [A: 3→1→2]
**   Algorithm:
**     1. วน loop หา node ก่อน last (prev) และ last
**     2. ตัด last ออก: prev->next = NULL
**     3. ต่อ last ไว้หน้า: last->next = *stack
**     4. อัพเดต head: *stack = last
**   ถ้า stack มีน้อยกว่า 2 elements → ไม่ทำอะไร
**
** rra(ps): reverse rotate stack a → print "rra\n"
** rrb(ps): reverse rotate stack b → print "rrb\n"
** rrr(ps): reverse rotate ทั้งสองพร้อมกัน → print "rrr\n"
**          ใช้เมื่อ cost_a และ cost_b ทั้งคู่เป็น negative
**          (ทั้งคู่ต้อง rrotate) ประหยัดได้ 1 operation ต่อ pair
*/

#include "push_swap.h"

static void	rrotate_one(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_ps *ps)
{
	rrotate_one(&ps->a);
	if (!ps->silent)
		write(1, "rra\n", 4);
}

void	rrb(t_ps *ps)
{
	rrotate_one(&ps->b);
	if (!ps->silent)
		write(1, "rrb\n", 4);
}

void	rrr(t_ps *ps)
{
	rrotate_one(&ps->a);
	rrotate_one(&ps->b);
	if (!ps->silent)
		write(1, "rrr\n", 4);
}
