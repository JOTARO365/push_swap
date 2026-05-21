/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ops_swap.c — Operations: sa, sb, ss
**
** swap_top(stack):
**   สลับ val และ idx ของ 2 node บนสุด IN-PLACE (ไม่ย้าย pointer)
**   เร็วกว่าการเปลี่ยน pointer เพราะลด pointer manipulation
**   ถ้า stack มีน้อยกว่า 2 elements → ไม่ทำอะไร
**
** sa(ps): swap top 2 ของ stack a → print "sa\n"
** sb(ps): swap top 2 ของ stack b → print "sb\n"
** ss(ps): sa และ sb พร้อมกัน → print "ss\n"
**         (ใช้ swap_top ทั้งสอง stack แล้วค่อย print "ss\n")
**         หมายเหตุ: ไม่เรียก sa()/sb() เพราะจะ print "sa\n"+"sb\n" แทน
*/

#include "push_swap.h"

static void	swap_top(t_node **stack)
{
	int	tmp_val;
	int	tmp_idx;

	if (!*stack || !(*stack)->next)
		return ;
	tmp_val = (*stack)->val;
	tmp_idx = (*stack)->idx;
	(*stack)->val = (*stack)->next->val;
	(*stack)->idx = (*stack)->next->idx;
	(*stack)->next->val = tmp_val;
	(*stack)->next->idx = tmp_idx;
}

void	sa(t_ps *ps)
{
	swap_top(&ps->a);
	if (!ps->silent)
		write(1, "sa\n", 3);
}

void	sb(t_ps *ps)
{
	swap_top(&ps->b);
	if (!ps->silent)
		write(1, "sb\n", 3);
}

void	ss(t_ps *ps)
{
	swap_top(&ps->a);
	swap_top(&ps->b);
	if (!ps->silent)
		write(1, "ss\n", 3);
}
