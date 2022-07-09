/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:03:01 by imabid            #+#    #+#             */
/*   Updated: 2022/02/10 20:57:37 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	is_neg(long *n, int *len)
{
	if (*n < 0)
	{
		*n *= -1;
		*len += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;

	nb = n;
	len = get_len(nb);
	is_neg(&nb, &len);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*(s + len) = '\0';
	if (nb == 0)
		*(s + 0) = '0';
	while (nb)
	{
		*(s + len - 1) = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	if (n < 0)
		*s = '-';
	return (s);
}
