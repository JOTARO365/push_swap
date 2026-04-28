/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:03:32 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/08/28 14:21:31 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;

	res = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s1 || !s2 || !res)
		return (NULL);
	ft_strlcpy(res, s1, (((ft_strlen(s1) + ft_strlen(s2)) + 1)));
	ft_strlcat(res, s2, (((ft_strlen(s1) + ft_strlen(s2)) + 1)));
	return (res);
}
