/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:17:03 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 17:29:22 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_5_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01CEP\n", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_exit(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_error(char **map)
{
	if (!check_top_and_bottom(map))
		return (print_error(NO_WALLS));
	if (!check_edges(map))
		return (print_error(NO_EDGES));
	if (!(check_line_size(map)))
		return (print_error(NO_LINES));
	if (check_player(map) > 1 || check_player(map) < 1)
		return (print_error(PLUS_PLAYER));
	if (check_exit(map) < 1)
		return (print_error(NO_EXIT));
	if (!check_5_characters(map))
		return (print_error(NO_CHARACTERS));
	return (1);
}
