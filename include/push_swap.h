/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 23:24:47 by waon-in           #+#    #+#             */
/*   Updated: 2024/10/15 18:49:32 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/include/libft.h"

typedef struct s_swap
{
	t_list		*swap_a;
	t_list		*swap_b;
	int		asize;
	int		bsize;
}	t_swap;

int	ft_check_num(char *nbr);

# endif
