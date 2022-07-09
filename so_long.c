/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:51:55 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 16:38:56 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	aff_imag(t_conf *conf)
{
	int	a;
	int	q;

	a = 0;
	while (conf->map[a])
	{
		q = 0;
		while (conf->map[a][q])
		{
			img_to_win(conf, a, q);
			q++;
		}
		a++;
	}
}

void	game_move(t_conf conf)
{
	mlx_hook(conf.mlx_win, 2, 1L << 0, player_move, &conf);
	mlx_hook(conf.mlx_win, 17, 0, close_win, &conf);
}

void	all_graphic(char **av)
{
	t_conf	conf;
	int		a;

	a = 0;
	conf.mlx = mlx_init();
	conf.map = map_read(av);
	game_img(&conf);
	conf.mlx_win = mlx_new_window(conf.mlx,
			conf.img.img_width * ft_strlen(conf.map[a]),
			conf.img.img_height * map_size(conf.map), "SoLong");
	aff_imag(&conf);
	game_move(conf);
	mlx_loop(conf.mlx);
}
