/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:51:42 by waon-in           #+#    #+#             */
/*   Updated: 2024/10/20 00:52:47 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_num(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+') && ft_isdigit(nbr[i + 1]) \
				&& (i == 0 || !ft_isdigit(nbr[i - 1])))) || ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_swap		*tab;
	char		**args;
	int			i;
	int			j;

	if (ac == 1)
		return (0);
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av;
	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (args[i])
	{
		if (!ft_check_num(args[i]))
		{
			handle_errors("error\n");
			if (ac == 2)
			{
				j = 0;
				while (args[j])
					free(args[j++]);
				free(args);
			}
			return (-1);
		}
		i++;
	}
	tab = malloc(sizeof(t_swap));
	if (tab->swap_a == NULL)
	{
		if (ac == 2)
		{
			j = 0;
			while (args[j])
				free(args[j++]);
			free(args);
		}
		return (-1);
	}
	tab->swap_b = NULL;
	tab->asize = ft_lstsize(tab->swap_a);
	tab->bsize = ft_lstsize(tab->swap_b);
	return (0);
}
