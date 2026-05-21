/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ops_push.c — Operations: pa, pb
**
** pa(ps): pop top ของ stack b → push ไปยัง top ของ stack a
**   ถ้า b ว่าง → ไม่ทำอะไร (subject specification)
**   print "pa\n" ถ้าทำการ push สำเร็จ
**
** pb(ps): pop top ของ stack a → push ไปยัง top ของ stack b
**   ถ้า a ว่าง → ไม่ทำอะไร
**   print "pb\n" ถ้าทำการ push สำเร็จ
**
** Flow ของ pa:
**   [B: x→y→z] [A: a→b→c]
**   → stack_pop(&b) คืน node x
**   → stack_push(&a, x)
**   → [B: y→z] [A: x→a→b→c]
*/

#include "push_swap.h"

void	pa(t_ps *ps)
{
	t_node	*node;

	if (!ps->b)
		return ;
	node = stack_pop(&ps->b);
	stack_push(&ps->a, node);
	if (!ps->silent)
		write(1, "pa\n", 3);
}

void	pb(t_ps *ps)
{
	t_node	*node;

	if (!ps->a)
		return ;
	node = stack_pop(&ps->a);
	stack_push(&ps->b, node);
	if (!ps->silent)
		write(1, "pb\n", 3);
}
