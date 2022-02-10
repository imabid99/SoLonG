/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:08:00 by imabid            #+#    #+#             */
/*   Updated: 2022/01/20 20:17:51 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_move_w(int x, t_conf *conf, t_pos pos)
{
	if (conf->map[x][pos.y] != '1')
	{
		print_move(conf, x, pos.y);
		if (conf->map[x][pos.y] == 'E' && !check_coin(conf->map))
		{
			conf->map[pos.x][pos.y] = '0';
			conf->map[x][pos.y] = 'E';
			exit(EXIT_SUCCESS);
		}
		if (conf->map[x][pos.y] != 'E')
		{
			conf->map[pos.x][pos.y] = '0';
			conf->map[x][pos.y] = 'P';
		}
		aff_imag(conf);
	}
}

void	to_move_d(int x, t_conf *conf, t_pos pos)
{
	if (conf->map[pos.x][x] != '1')
	{
		print_move(conf, pos.x, x);
		if (conf->map[pos.x][x] == 'E' && !check_coin(conf->map))
		{
			conf->map[pos.x][pos.y] = '0';
			conf->map[pos.x][x] = 'E';
			exit(EXIT_SUCCESS);
		}
		if (conf->map[pos.x][x] != 'E')
		{
			conf->map[pos.x][pos.y] = '0';
			conf->map[pos.x][x] = 'P';
		}
		conf->player.img = mlx_xpm_file_to_image
			(conf->mlx, "as/player_only.xpm", &conf->player.player_width,
				&conf->player.player_height);
		aff_imag(conf);
	}
}

void	to_move_s(int x, t_conf *conf, t_pos pos)
{
	if (conf->map[x][pos.y] != '1')
	{
		print_move(conf, x, pos.y);
		if (conf->map[x][pos.y] == 'E' && !check_coin(conf->map))
		{
			conf->map[pos.x][pos.y] = '0';
			conf->map[x][pos.y] = 'E';
			exit(EXIT_SUCCESS);
		}
		if (conf->map[x][pos.y] != 'E')
		{
			conf->map[pos.x][pos.y] = '0';
			conf->map[x][pos.y] = 'P';
		}
		aff_imag(conf);
	}
}

void	to_move_a(int x, t_conf *conf, t_pos pos)
{
	if (conf->map[pos.x][x] != '1')
	{
		print_move(conf, pos.x, x);
		if (conf->map[pos.x][x] == 'E' && !check_coin(conf->map))
		{
			conf->map[pos.x][pos.y] = '0';
			conf->map[pos.x][x] = 'E';
			exit(EXIT_SUCCESS);
		}
		if (conf->map[pos.x][x] != 'E')
		{
			conf->map[pos.x][pos.y] = '0';
			conf->map[pos.x][x] = 'P';
		}
		conf->player.img = mlx_xpm_file_to_image
			(conf->mlx, "as/player_only1.xpm", &conf->player.player_width,
				&conf->player.player_height);
		aff_imag(conf);
	}
}

int	player_move(int key, void *param)
{
	t_pos	pos;
	t_conf	*conf;

	conf = (t_conf *)param;
	pos = player_pos(conf->map);
	if (key == ESC)
		exit(0);
	if (key == W)
		to_move_w(pos.x - 1, conf, pos);
	if (key == D)
		to_move_d(pos.y + 1, conf, pos);
	if (key == S)
		to_move_s(pos.x + 1, conf, pos);
	if (key == A)
		to_move_a(pos.y - 1, conf, pos);
	if (key != A && key != S && key != D && key != W)
	{
		print_error(ANOTHER_KEY);
		exit(0);
	}
	return (0);
}
