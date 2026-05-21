/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** main.c — Entry point ของโปรแกรม push_swap
**
** main():
**   1. argc < 2  → ไม่มี argument → return 0 (ไม่ print อะไร)
**   2. parse_args()  → validate input, สร้าง stack a เป็น linked list
**                      (argv[1] = top, argv[argc-1] = bottom)
**   3. normalize()   → แปลงค่าจริงเป็น rank 0..n-1 เก็บใน node->idx
**                      ทำให้ algorithm ทำงานกับ relative position แทนค่าจริง
**   4. is_sorted()   → ถ้า sorted อยู่แล้ว ไม่ต้อง print อะไร
**   5. sort_small()  → n <= 5: hardcode/brute force (เร็วและน้อย ops)
**      sort_large()  → n > 5 : Turkish sort (greedy cost-based insertion)
**   6. ps_free()     → คืน memory ทั้งหมด
**
** error_exit() ถูกเรียกจาก parse.c เมื่อ input ไม่ถูกต้อง:
**   → ps_free → write "Error\n" ไป stderr (fd=2) → exit(1)
*/

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;
	int		size;

	if (argc < 2)
		return (0);
	ps = parse_args(argc, argv);
	normalize(ps);
	size = stack_size(ps->a);
	if (size > 1 && !is_sorted(ps->a))
	{
		if (size <= 5)
			sort_small(ps);
		else
			sort_large(ps);
	}
	ps_free(ps);
	return (0);
}
