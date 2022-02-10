/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:31:04 by imabid            #+#    #+#             */
/*   Updated: 2022/01/19 19:50:48 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_img(t_conf *conf)
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
