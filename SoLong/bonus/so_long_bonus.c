/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:51:55 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 17:27:34 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win_bonus(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	aff_imag_bonus(t_conf *conf)
{
	int	a;
	int	q;

	a = 0;
	while (conf->map[a])
	{
		q = 0;
		while (conf->map[a][q])
		{
			img_to_win_bonus(conf, a, q);
			img_to_win_enemy_bonus(conf, a, q);
			q++;
		}
		a++;
	}
}

void	game_move_bonus(t_conf conf)
{
	mlx_hook(conf.mlx_win, 2, 1L << 0, player_move_bonus, &conf);
	mlx_hook(conf.mlx_win, 17, 0, close_win_bonus, &conf);
	mlx_loop_hook(conf.mlx, enemy_move_bonus, &conf);
}

void	all_graphic_bonus(char **av)
{
	t_conf	conf;
	int		a;

	a = 0;
	conf.count = 0;
	conf.mlx = mlx_init();
	conf.map = map_read_bonus(av);
	game_img_bonus(&conf);
	game_img_1_bonus(&conf);
	conf.mlx_win = mlx_new_window(conf.mlx,
			conf.img.img_width * ft_strlen(conf.map[a]),
			conf.img.img_height * map_size_bonus(conf.map), "SoLong");
	aff_imag_bonus(&conf);
	game_move_bonus(conf);
	mlx_loop(conf.mlx);
}
