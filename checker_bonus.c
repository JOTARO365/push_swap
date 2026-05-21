/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checker_bonus.c — Bonus: อ่าน operations จาก stdin แล้วตรวจผล
**
** apply_op(ps, line):
**   รับ line หนึ่งบรรทัดจาก stdin (get_next_line)
**   เปรียบเทียบกับ 11 operations ที่ valid ด้วย ft_strncmp
**   เรียก function op ที่ตรงกัน (ps->silent=1 → ไม่ print ชื่อ op)
**   ถ้า line ไม่ตรงกับ operation ใด → error_exit
**
** read_ops(ps):
**   วน get_next_line(stdin) จนได้ NULL (EOF)
**   แต่ละบรรทัด → apply_op → free
**
** main():
**   1. parse_args + normalize (เหมือน push_swap)
**   2. ตั้ง ps->silent = 1 เพื่อปิด output ของ operations
**   3. read_ops → apply ทุก operation จาก stdin
**   4. ตรวจผล: a sorted + b ว่าง → "OK", อื่นๆ → "KO"
*/

#include "push_swap.h"

static void	apply_op(t_ps *ps, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(ps);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(ps);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(ps);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(ps);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(ps);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(ps);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(ps);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(ps);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(ps);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(ps);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(ps);
	else
		error_exit(ps);
}

static void	read_ops(t_ps *ps)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_op(ps, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (0);
	ps = parse_args(argc, argv);
	normalize(ps);
	ps->silent = 1;
	read_ops(ps);
	if (is_sorted(ps->a) && !ps->b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ps_free(ps);
	return (0);
}
