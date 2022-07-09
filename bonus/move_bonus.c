/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:08:00 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 17:28:28 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	to_move_w_bonus(int x, t_conf *conf, t_pos pos)
{
	if (conf->map[x][pos.y] != '1')
	{
		print_move_bonus(conf, x, pos.y);
		if (conf->map[x][pos.y] == 'Y')
			exit(0);
		if (conf->map[x][pos.y] == 'E' && !check_coin_bonus(conf->map))
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
		aff_imag_bonus(conf);
	}
}

void	to_move_d_bonus(int x, t_conf *conf, t_pos pos)
{
	if (conf->map[pos.x][x] != '1')
	{
		print_move_bonus(conf, pos.x, x);
		if (conf->map[pos.x][x] == 'Y')
			exit(0);
		if (conf->map[pos.x][x] == 'E' && !check_coin_bonus(conf->map))
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
		aff_imag_bonus(conf);
	}
}

void	to_move_s_bonus(int x, t_conf *conf, t_pos pos)
{
	if (conf->map[x][pos.y] != '1')
	{
		print_move_bonus(conf, x, pos.y);
		if (conf->map[x][pos.y] == 'Y')
			exit(0);
		if (conf->map[x][pos.y] == 'E' && !check_coin_bonus(conf->map))
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
		aff_imag_bonus(conf);
	}
}

void	to_move_a_bonus(int x, t_conf *conf, t_pos pos)
{
	if (conf->map[pos.x][x] != '1')
	{
		print_move_bonus(conf, pos.x, x);
		if (conf->map[pos.x][x] == 'Y')
			exit(0);
		if (conf->map[pos.x][x] == 'E' && !check_coin_bonus(conf->map))
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
		aff_imag_bonus(conf);
	}
}

int	player_move_bonus(int key, void *param)
{
	t_pos	pos;
	t_conf	*conf;

	conf = (t_conf *)param;
	pos = player_pos_bonus(conf->map);
	if (key == ESC)
		exit(0);
	if (key == W)
		to_move_w_bonus(pos.x - 1, conf, pos);
	if (key == D)
		to_move_d_bonus(pos.y + 1, conf, pos);
	if (key == S)
		to_move_s_bonus(pos.x + 1, conf, pos);
	if (key == A)
		to_move_a_bonus(pos.y - 1, conf, pos);
	if (key != A && key != S && key != D && key != W)
	{
		print_error_bonus(ANOTHER_KEY);
		exit(0);
	}
	return (0);
}
