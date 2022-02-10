/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:36:55 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 17:27:13 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_error_bonus(char *error)
{
	printf("Error\n%s", error);
	return (-1);
}

int	check_top_and_bottom_bonus(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[i - 1][j] != '\0')
	{
		if (map[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_edges_bonus(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_line_size_bonus(char **map)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(map[i]) - 1;
	i += 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) - 1 > size || ft_strlen(map[i]) - 1 < size)
			return (0);
		i++;
	}
	return (1);
}
