/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:33:10 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 17:37:42 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_to_win_bonus(t_conf *conf, int a, int q)
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
	if (!check_coin_bonus(conf->map) && conf->map[a][q] == 'E')
		mlx_put_image_to_window(conf->mlx, conf->mlx_win,
			conf->exit1.img, q * conf->exit1.exit1_width,
			a * conf->exit1.exit1_height);
	mlx_string_put(conf->mlx, conf->mlx_win, 5, 5, C2, "count : ");
	mlx_string_put(conf->mlx, conf->mlx_win, 80, 5, C1, ft_itoa(conf->count));
}

void	img_to_win_enemy_bonus(t_conf *conf, int a, int q)
{
	static int	i;

	while (i > 3)
		i = 0;
	if (conf->map[a][q] == 'Y')
		mlx_put_image_to_window(conf->mlx, conf->mlx_win,
			conf->enemy[i].img, q * conf->enemy[i].enemy_width,
			a * conf->enemy[i].enemy_height);
	i++;
}
