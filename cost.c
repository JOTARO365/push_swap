/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** cost.c — Cost calculation สำหรับ Turkish sort (greedy insertion)
**
** find_min_in_a(ps):
**   หา position ของ element ที่มี idx น้อยที่สุดใน stack a ในขณะนั้น
**   (ต่างจาก find_min_pos ใน utils.c ที่ค้นหา idx==0 ซึ่งอาจอยู่ใน b)
**
** find_target(ps, b_idx):
**   หา position ใน a ที่ควร insert element จาก b
**   ถ้า b_idx เล็กกว่า element บางตัวใน a → target = ตำแหน่ง
**   element ที่มี idx น้อยสุดที่ยังมากกว่า b_idx (successor)
**   ถ้า b_idx ใหญ่กว่าทุก element ใน a → target = find_min_in_a
**   (element ที่เล็กสุดใน a จะอยู่ถัดไปในวง circular sorted)
**
** cost_of(pos, size):
**   pos <= size/2 → +pos (ra direction)
**   pos >  size/2 → -(size-pos) (rra direction)
**
** pick_cost(ps, ptr, pos):
**   combined cost สำหรับ insert element ptr จาก b ไปยัง a
**   same sign → max(|ca|,|cb|), ต่าง sign → |ca|+|cb|
**
** best_b_pos(ps):
**   หา position ใน b ที่มี pick_cost ต่ำสุด
*/

#include "push_swap.h"

static int	find_min_in_a(t_ps *ps)
{
	t_node	*ptr;
	int		pos;
	int		min_pos;
	int		min_idx;

	ptr = ps->a;
	pos = 0;
	min_pos = 0;
	min_idx = INT_MAX;
	while (ptr)
	{
		if (ptr->idx < min_idx)
		{
			min_idx = ptr->idx;
			min_pos = pos;
		}
		ptr = ptr->next;
		pos++;
	}
	return (min_pos);
}

int	find_target(t_ps *ps, int b_idx)
{
	t_node	*ptr;
	int		pos;
	int		best_pos;
	int		best_idx;

	ptr = ps->a;
	pos = 0;
	best_pos = find_min_in_a(ps);
	best_idx = INT_MAX;
	while (ptr)
	{
		if (ptr->idx > b_idx && ptr->idx < best_idx)
		{
			best_idx = ptr->idx;
			best_pos = pos;
		}
		ptr = ptr->next;
		pos++;
	}
	return (best_pos);
}

int	cost_of(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}

static int	pick_cost(t_ps *ps, t_node *ptr, int pos)
{
	int		target;
	int		ca;
	int		cb;

	target = find_target(ps, ptr->idx);
	ca = cost_of(target, stack_size(ps->a));
	cb = cost_of(pos, stack_size(ps->b));
	if ((ca >= 0 && cb >= 0) || (ca <= 0 && cb <= 0))
	{
		if (ft_abs(ca) > ft_abs(cb))
			return (ft_abs(ca));
		return (ft_abs(cb));
	}
	return (ft_abs(ca) + ft_abs(cb));
}

int	best_b_pos(t_ps *ps)
{
	t_node	*ptr;
	int		pos;
	int		best_pos;
	int		best_cost;
	int		cur;

	ptr = ps->b;
	pos = 0;
	best_pos = 0;
	best_cost = INT_MAX;
	while (ptr)
	{
		cur = pick_cost(ps, ptr, pos);
		if (cur < best_cost)
		{
			best_cost = cur;
			best_pos = pos;
		}
		ptr = ptr->next;
		pos++;
	}
	return (best_pos);
}
