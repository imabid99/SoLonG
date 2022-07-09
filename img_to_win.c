/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:33:10 by imabid            #+#    #+#             */
/*   Updated: 2022/01/18 18:03:09 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_win(t_conf *conf, int a, int q)
{
	if (conf->map[a][q] == '1')
		mlx_put_image_to_window(conf->mlx, conf->mlx_win,
			conf->img.img, q * conf->img.img_width, a * conf->img.img_height);
	if (conf->map[a][q] == 'C')
		mlx_put_image_to_window(conf->mlx, conf->mlx_win,
			conf->coin.img, q * conf->coin.coin_width,
			a * conf->coin.coin_height);
	if (conf->map[a][q] == '0')
		mlx_put_image_to_window(conf->mlx, conf->mlx_win,
			conf->background.img, q * conf->background.background_width,
			a * conf->background.background_height);
	if (conf->map[a][q] == 'P')
		mlx_put_image_to_window(conf->mlx, conf->mlx_win,
			conf->player.img, q * conf->player.player_width,
			a * conf->player.player_height);
	if (conf->map[a][q] == 'E')
		mlx_put_image_to_window(conf->mlx, conf->mlx_win,
			conf->exit.img, q * conf->exit.exit_width,
			a * conf->exit.exit_height);
	if (!check_coin(conf->map) && conf->map[a][q] == 'E')
		mlx_put_image_to_window(conf->mlx, conf->mlx_win,
			conf->exit1.img, q * conf->exit1.exit1_width,
			a * conf->exit1.exit1_height);
}
