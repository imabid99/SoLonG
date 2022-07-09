/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:49:28 by imabid            #+#    #+#             */
/*   Updated: 2022/01/13 15:06:08 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		a = s1[i];
		b = s2[i];
		if (a && b == '\0')
			return (a);
		if (a == '\0' && b)
			return (-b);
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
