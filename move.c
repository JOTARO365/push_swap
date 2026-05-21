/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** move.c — Execute rotation moves สำหรับ Turkish sort insertion
**
** rotate_a_by(ps, ca):
**   Apply ca rotations ไปยัง stack a
**   ca > 0 → ra ca ครั้ง (forward)
**   ca < 0 → rra |ca| ครั้ง (backward)
**
** rotate_b_by(ps, cb):
**   เหมือน rotate_a_by แต่ทำกับ stack b
**
** do_same_dir(ps, &ca, &cb):
**   ถ้า ca และ cb ทั้งคู่บวก → ใช้ rr (ประหยัด ops)
**   ถ้า ca และ cb ทั้งคู่ลบ  → ใช้ rrr (ประหยัด ops)
**   ลด ca, cb ไปพร้อมกันทีละ 1 จนกว่าจะต่างทิศหรือเป็น 0
**   หลังจากนี้: ca และ cb อาจมีค่าที่เหลือที่ต้องทำแยก
**
** do_move(ps, pos_a, pos_b):
**   Full execution ของการ insert element จาก position pos_b ใน b
**   เข้าไปยัง position pos_a ใน a:
**   1. คำนวณ ca, cb จาก cost_of()
**   2. do_same_dir() → ใช้ rr/rrr สำหรับส่วนที่ทิศเดียวกัน
**   3. rotate_a_by() → หมุน a ที่เหลือด้วย ra/rra
**   4. rotate_b_by() → หมุน b ที่เหลือด้วย rb/rrb
**   5. pa() → push top ของ b ไปยัง top ของ a
*/

#include "push_swap.h"

static void	rotate_a_by(t_ps *ps, int ca)
{
	while (ca > 0)
	{
		ra(ps);
		ca--;
	}
	while (ca < 0)
	{
		rra(ps);
		ca++;
	}
}

static void	rotate_b_by(t_ps *ps, int cb)
{
	while (cb > 0)
	{
		rb(ps);
		cb--;
	}
	while (cb < 0)
	{
		rrb(ps);
		cb++;
	}
}

static void	do_same_dir(t_ps *ps, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(ps);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(ps);
		(*ca)++;
		(*cb)++;
	}
}

void	do_move(t_ps *ps, int pos_a, int pos_b)
{
	int	ca;
	int	cb;

	ca = cost_of(pos_a, stack_size(ps->a));
	cb = cost_of(pos_b, stack_size(ps->b));
	do_same_dir(ps, &ca, &cb);
	rotate_a_by(ps, ca);
	rotate_b_by(ps, cb);
	pa(ps);
}
