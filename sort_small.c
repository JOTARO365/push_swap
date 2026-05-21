/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sort_small.c — Sorting สำหรับ n = 2..5 elements
**
** sort_2(ps):
**   ถ้า top.idx > second.idx → sa. Max 1 op.
**
** sort_3(ps):
**   ครอบคลุม 6 permutations โดยใช้ logic:
**   - top มี idx ใหญ่สุด → ra (ดัน top ลงล่าง)
**   - middle มี idx ใหญ่สุด → rra (ดึง bottom ขึ้นบน)
**   - top > second → sa
**   - ตรวจอีกครั้งหลังแต่ละ op เพราะ state เปลี่ยน
**   Max 2 ops.
**
** find_idx_pos(stack, target):
**   scan linked list หา position (0-indexed) ของ node ที่ idx == target
**   ไม่แก้ไข stack ใดๆ
**
** bring_to_top(ps, target_idx):
**   นำ node ที่มี idx == target_idx ขึ้นมาที่ TOP ของ stack a
**   ถ้า position <= size/2 → ใช้ ra (ถูกกว่า)
**   ถ้า position > size/2  → ใช้ rra (ถูกกว่า เพราะวนอ้อมน้อยกว่า)
**
** sort_small(ps):
**   n=2 → sort_2
**   n=3 → sort_3
**   n=4 → bring idx=0 to top → pb → sort_3 → pa
**   n=5 → bring idx=0 → pb → bring idx=1 → pb → sort_3 → pa → pa
*/

#include "push_swap.h"

void	sort_2(t_ps *ps)
{
	if (ps->a->idx > ps->a->next->idx)
		sa(ps);
}

void	sort_3(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a->idx;
	b = ps->a->next->idx;
	c = ps->a->next->next->idx;
	if (a > b && a > c)
		ra(ps);
	else if (b > a && b > c)
		rra(ps);
	else if (a > b)
		sa(ps);
	if (ps->a->idx > ps->a->next->idx)
		sa(ps);
}

static int	find_idx_pos(t_node *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack && stack->idx != target)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	bring_to_top(t_ps *ps, int target_idx)
{
	int	pos;
	int	size;

	pos = find_idx_pos(ps->a, target_idx);
	size = stack_size(ps->a);
	if (pos <= size / 2)
	{
		while (ps->a->idx != target_idx)
			ra(ps);
	}
	else
	{
		while (ps->a->idx != target_idx)
			rra(ps);
	}
}

void	sort_small(t_ps *ps)
{
	int	size;

	size = stack_size(ps->a);
	if (size == 2)
		return (sort_2(ps));
	if (size == 3)
		return (sort_3(ps));
	bring_to_top(ps, 0);
	pb(ps);
	if (size == 5)
	{
		bring_to_top(ps, 1);
		pb(ps);
	}
	sort_3(ps);
	pa(ps);
	if (size == 5)
		pa(ps);
}
