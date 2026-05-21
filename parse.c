/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** parse.c — รับ argv, validate, สร้าง stack a
**
** has_dup(stack, val):
**   วน scan stack ตรวจว่ามี val อยู่แล้วหรือไม่
**   คืน 1 ถ้า duplicate, 0 ถ้าไม่ซ้ำ
**
** append_node(head, tail, node):
**   เพิ่ม node ต่อท้าย linked list (maintain order: argv[1] = top)
**
** build_stack(argc, argv, ps):
**   วน loop ผ่าน argv[1..argc-1]
**   validate แต่ละ argument → สร้าง node → append ลง list
**   คืน pointer ไป head ของ list (= top of stack)
**
** parse_args(argc, argv):
**   สร้าง t_ps struct → เรียก build_stack → คืน ps
**   ถ้า malloc ล้มเหลว → error_exit()
*/

#include "push_swap.h"

int	has_dup(t_node *stack, int val)
{
	while (stack)
	{
		if (stack->val == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	append_node(t_node **head, t_node **tail, t_node *node)
{
	if (!*head)
	{
		*head = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		*tail = node;
	}
}

static t_node	*build_stack(int argc, char **argv, t_ps *ps)
{
	t_node	*head;
	t_node	*tail;
	t_node	*node;
	int		i;

	head = NULL;
	tail = NULL;
	i = 1;
	while (i < argc)
	{
		if (!valid_int(argv[i]))
			error_exit(ps);
		if (has_dup(head, ft_atoi(argv[i])))
			error_exit(ps);
		node = new_node(ft_atoi(argv[i]));
		if (!node)
			error_exit(ps);
		append_node(&head, &tail, node);
		i++;
	}
	return (head);
}

t_ps	*parse_args(int argc, char **argv)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (!ps)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	ps->a = NULL;
	ps->b = NULL;
	ps->silent = 0;
	ps->a = build_stack(argc, argv, ps);
	return (ps);
}
