/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** normalize.c — แปลงค่า integer จริงเป็น rank 0..n-1
**
** ทำไมต้อง normalize?
**   Algorithm ทำงานกับ "ลำดับ" ของค่า ไม่ใช่ค่าจริง
**   เช่น [-999, 0, 42, 1000000] → rank [0, 1, 2, 3]
**   ทำให้เปรียบเทียบและหา target position ง่ายขึ้น
**   ลด complexity: ไม่ต้องใช้ binary search หรือ sort จริง
**
** count_smaller(stack, val):
**   นับจำนวน node ใน stack ที่มี val < val ที่รับมา
**   นี่คือ rank ของ val นั้น (O(n) per node → O(n²) total)
**   เพียงพอสำหรับ n <= 500
**
** normalize(ps):
**   วน loop แต่ละ node ใน stack a
**   เรียก count_smaller() เพื่อหา rank → เก็บใน node->idx
**   หลังจาก normalize: node ที่มี val เล็กสุด → idx=0
**                       node ที่มี val ใหญ่สุด → idx=n-1
*/

#include "push_swap.h"

static int	count_smaller(t_node *stack, int val)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->val < val)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	normalize(t_ps *ps)
{
	t_node	*ptr;

	ptr = ps->a;
	while (ptr)
	{
		ptr->idx = count_smaller(ps->a, ptr->val);
		ptr = ptr->next;
	}
}
