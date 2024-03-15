/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:35:29 by waon-in           #+#    #+#             */
/*   Updated: 2023/10/07 16:45:51 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*from;
	unsigned char		*to;
	size_t				i;

	i = 0;
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if ((!from && !to) || len == 0)
		return (to);
	if (from > to)
	{
		while (i < len)
		{
			to[i] = from[i];
			i++;
		}
	}
	else
	{
		while (len-- != 0)
			to[len] = from[len];
	}
	return (to);
}
