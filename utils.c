/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** utils.c — Utility functions ที่ใช้ร่วมกันทั่วโปรแกรม
**
** is_sorted(stack):
**   ตรวจว่า stack a เรียง ascending ตาม idx หรือไม่
**   วน scan เปรียบเทียบ idx ของแต่ละ node กับ node ถัดไป
**   คืน 1 ถ้า sorted (หรือ stack ว่าง), คืน 0 ถ้าไม่
**
** find_min_pos(stack):
**   หา position (0-indexed จาก top) ของ node ที่มี idx = 0
**   หลัง normalize, idx=0 = element ที่เล็กที่สุด
**   ใช้สำหรับ rotate_min_to_top() ใน sort_large
**
** ft_abs(n):
**   คืนค่า absolute value ของ n
**   ใช้สำหรับ cost calculation (cost อาจเป็น negative)
**
** ps_free(ps):
**   free ทั้ง stack a, stack b, และ struct ps เอง
**
** error_exit(ps):
**   เรียกเมื่อ input ไม่ valid
**   ps_free → write "Error\n" ไป stderr → exit(1)
*/

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->idx > stack->next->idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min_pos(t_node *stack)
{
	int	pos;

	pos = 0;
	while (stack && stack->idx != 0)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ps_free(t_ps *ps)
{
	if (!ps)
		return ;
	stack_free(&ps->a);
	stack_free(&ps->b);
	free(ps);
}

void	error_exit(t_ps *ps)
{
	ps_free(ps);
	write(2, "Error\n", 6);
	exit(1);
}
