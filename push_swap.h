/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** push_swap.h — Master header สำหรับ push_swap project
**
** โครงสร้างข้อมูล:
**
**   t_node — node หนึ่งตัวใน linked list ที่ใช้แทน stack
**     .val  : ค่า integer จริงที่รับมาจาก argument
**     .idx  : rank หลัง normalize (0 = เล็กสุด, n-1 = ใหญ่สุด)
**     .next : pointer ไป node ถัดไป (ลึกกว่าใน stack)
**
**   t_ps — struct เก็บ stack ทั้งสอง (a และ b)
**     .a : pointer ไป top ของ stack a
**     .b : pointer ไป top ของ stack b
**
** Flow รวมของโปรแกรม:
**   1. parse_args()  → รับ argv, validate, สร้าง stack a เป็น linked list
**   2. normalize()   → แปลงค่าจริงเป็น rank 0..n-1 เก็บใน .idx
**   3. sort*()       → เลือก algorithm ตามขนาด stack แล้ว output operations
**   4. ps_free()     → คืน memory ทั้งหมด
**
** Allowed functions: read, write, malloc, free, exit, ft_atoi (libft)
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

/*
** t_node: หนึ่ง element ใน stack (linked list node)
*/
typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
}	t_node;

/*
** t_ps: คู่ stack ที่ใช้ตลอดโปรแกรม
*/
typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	int		silent;
}	t_ps;

/* ── parse.c ──────────────────────────────────────────────── */
int		valid_int(const char *s);
int		has_dup(t_node *stack, int val);
t_ps	*parse_args(int argc, char **argv);

/* ── stack.c ──────────────────────────────────────────────── */
t_node	*new_node(int val);
void	stack_push(t_node **top, t_node *node);
t_node	*stack_pop(t_node **top);
int		stack_size(t_node *top);
void	stack_free(t_node **top);

/* ── normalize.c ──────────────────────────────────────────── */
void	normalize(t_ps *ps);

/* ── ops_swap.c ───────────────────────────────────────────── */
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);

/* ── ops_push.c ───────────────────────────────────────────── */
void	pa(t_ps *ps);
void	pb(t_ps *ps);

/* ── ops_rotate.c ─────────────────────────────────────────── */
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);

/* ── ops_rrotate.c ────────────────────────────────────────── */
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

/* ── sort_small.c ─────────────────────────────────────────── */
void	sort_2(t_ps *ps);
void	sort_3(t_ps *ps);
void	sort_small(t_ps *ps);

/* ── sort_large.c ─────────────────────────────────────────── */
void	sort_large(t_ps *ps);

/* ── cost.c ───────────────────────────────────────────────── */
int		find_target(t_ps *ps, int b_idx);
int		cost_of(int pos, int size);
int		best_b_pos(t_ps *ps);

/* ── move.c ───────────────────────────────────────────────── */
void	do_move(t_ps *ps, int pos_a, int pos_b);

/* ── utils.c ──────────────────────────────────────────────── */
int		is_sorted(t_node *stack);
int		find_min_pos(t_node *stack);
int		ft_abs(int n);
void	ps_free(t_ps *ps);
void	error_exit(t_ps *ps);

#endif
