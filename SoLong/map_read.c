/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:37:42 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 17:31:06 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_line(char **av)
{
	int		fd;
	char	*line;
	int		line_size;

	line_size = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_size);
}

void	ft_init(t_map *map)
{
	map->j = 0;
	map->i = 0;
	map->f = 0;
}

char	**read_map(char **av)
{
	t_map	map;

	ft_init(&map);
	map.line_size = number_of_line(av);
	map.map = (char **)malloc(sizeof(char *) * (map.line_size + 1));
	map.fd = open(av[1], O_RDONLY);
	map.line = get_next_line(map.fd);
	if (!map.line)
		print_error(NO_MAP);
	while (map.line != NULL)
	{
		map.map[map.j] = (char *)malloc(ft_strlen(map.line) + 1);
		while (map.line[map.i] != '\0')
			map.map[map.j][map.f++] = map.line[map.i++];
		map.map[map.j++][map.f] = '\0';
		map.f = 0;
		map.i = 0;
		free(map.line);
		map.line = get_next_line(map.fd);
	}
	close(map.fd);
	map.map[map.j] = NULL;
	return (map.map);
}

static int	ft_strlen_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**map_read(char **av)
{
	char	**map;
	int		i;

	i = -1;
	map = read_map(av);
	if (check_error(map) == -1)
	{
		while (++i < ft_strlen_map(map))
			free(map[i]);
		free(map);
		exit(1);
	}
	return (map);
}
