/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:31:04 by imabid            #+#    #+#             */
/*   Updated: 2022/01/21 16:06:01 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_img_bonus(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image
		(conf->mlx, "as/ABnyConv.com__rsz_wall1.xpm",
			&conf->img.img_width, &conf->img.img_height);
	conf->coin.img = mlx_xpm_file_to_image
		(conf->mlx, "as/rsz_1folder_1.xpm",
			&conf->coin.coin_width, &conf->coin.coin_height);
	conf->player.img = mlx_xpm_file_to_image
		(conf->mlx, "as/player_only.xpm", &conf->player.player_width,
			&conf->player.player_height);
	conf->exit.img = mlx_xpm_file_to_image
		(conf->mlx, "as/AB.xpm", &conf->exit.exit_width,
			&conf->exit.exit_height);
	conf->exit1.img = mlx_xpm_file_to_image
		(conf->mlx, "as/AnyConv.com__door_open.xpm",
			&conf->exit1.exit1_width, &conf->exit1.exit1_height);
	conf->background.img = mlx_xpm_file_to_image
		(conf->mlx, "as/baack2.xpm",
			&conf->background.background_width,
			&conf->background.background_height);
}

void	game_img_1_bonus(t_conf *conf)
{
	conf->enemy[0].img = mlx_xpm_file_to_image
		(conf->mlx, "as/enemy_only.xpm", &conf->enemy[0].enemy_width,
			&conf->enemy[0].enemy_height);
	conf->enemy[1].img = mlx_xpm_file_to_image
		(conf->mlx, "as/enemy_only1.xpm", &conf->enemy[1].enemy_width,
			&conf->enemy[1].enemy_height);
	conf->enemy[2].img = mlx_xpm_file_to_image
		(conf->mlx, "as/enemy_only2.xpm", &conf->enemy[2].enemy_width,
			&conf->enemy[2].enemy_height);
}
