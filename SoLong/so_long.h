/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:28:05 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 17:37:25 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	void	*coin;
	void	*player;
	void	*exit;
	void	*enemy;
	void	*enemy1;
	void	*exit1;
	void	*background;
	int		img_height;
	int		img_width;
	int		coin_height;
	int		coin_width;
	int		player_height;
	int		player_width;
	int		player1_height;
	int		player1_width;
	int		exit_height;
	int		exit_width;
	int		background_height;
	int		background_width;
	int		exit1_height;
	int		exit1_width;
	int		enemy_height;
	int		enemy_width;
	int		enemy1_height;
	int		enemy1_width;
}		t_data;
typedef struct s_map
{
	char	**map;
	char	*line;
	int		fd;
	int		line_size;
	int		i;
	int		j;
	int		f;
}	t_map;

typedef struct s_pos {
	int		x;
	int		y;	
}		t_pos;

typedef struct s_pos_en
{
	int		x;
	int		y;	
}		t_pos_en;
typedef struct s_staticc
{
	int		i;
	int		f;	
}		t_staticc;
typedef struct s_pos_z
{
	int		x;
	int		y;	
}		t_pos_z;

typedef struct s_conf {
	t_data	img;
	t_data	coin;
	t_data	player;
	t_data	player1;
	t_data	exit;
	t_data	exit1;
	t_data	background;
	t_data	enemy[3];
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		count;
}		t_conf;

typedef struct s_all
{
	t_pos_en	pos_en;
	t_conf		*conf;
	t_staticc	staticc;
}		t_all;

# define C2 0xC34A6A
# define C1 0x7AE2B3
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define DN 17
# define NO_WALLS "The map is not closed.\n"
# define NO_EDGES "The edges of the map are invalid\n"
# define NO_LINES "The map is not a rectangle.\n"
# define PLUS_PLAYER "There can be only one player\n"
# define NO_CHARACTERS "Map contain invalid character.\n"
# define NO_EXIT "Map does not contain exit gate.\n"
# define NOT_VALID_FILE "Not a valid .ber file.\n"
# define NO_USAGE "Usage : ./so_long <map.ber>.\n"
# define NO_MAP "Empty map\n"
# define NO_FILE "No file in directory\n"
# define ANOTHER_KEY "PLEASE Press A_W_D_S\n"

int			number_of_line(char **av);
char		**read_map(char **av);
void		lets_free(char **map);
int			check_top_and_bottom(char **map);
int			check_edges(char **map);
int			print_error(char *error);
char		**map_read(char **av);
void		all_graphic(char **av);
int			check_line_size(char **map);
int			check_5_characters(char **map);
int			check_player(char **map);
int			check_exit(char **map);
int			check_error(char **map);
void		to_move_a(int x, t_conf *conf, t_pos pos);
void		to_move_s(int x, t_conf *conf, t_pos pos);
void		to_move_d(int x, t_conf *conf, t_pos pos);
void		to_move_w(int x, t_conf *conf, t_pos pos);
int			player_move(int key, void *param);
t_pos		player_pos(char **map);
int			check_coin(char **map);
void		game_img(t_conf *conf);
void		aff_imag(t_conf *conf);
int			map_size(char **map);
void		print_move(t_conf *conf, int x, int y);
void		img_to_win(t_conf *conf, int a, int q);
char		*get_next_line(int fd);
char		*ft_strjoin1(char *s1, char *s2);
size_t		ft_strlen1(const	char *s);
char		*ft_strchr1(const char *s, int c);
int			number_of_line_bonus(char **av);
char		**read_map_bonus(char **av);
void		lets_free_bonus(char **map);
int			check_top_and_bottom_bonus(char **map);
int			check_edges_bonus(char **map);
int			print_error_bonus(char *error);
char		**map_read_bonus(char **av);
void		all_graphic_bonus(char **av);
int			check_line_size_bonus(char **map);
int			check_5_characters_bonus(char **map);
int			check_player_bonus(char **map);
int			check_exit_bonus(char **map);
int			check_error_bonus(char **map);
void		to_move_a_bonus(int x, t_conf *conf, t_pos pos);
void		to_move_s_bonus(int x, t_conf *conf, t_pos pos);
void		to_move_d_bonus(int x, t_conf *conf, t_pos pos);
void		to_move_w_bonus(int x, t_conf *conf, t_pos pos);
int			player_move_bonus(int key, void *param);
t_pos		player_pos_bonus(char **map);
int			check_coin_bonus(char **map);
void		game_img_bonus(t_conf *conf);
void		aff_imag_bonus(t_conf *conf);
int			map_size_bonus(char **map);
void		print_move_bonus(t_conf *conf, int x, int y);
void		img_to_win_bonus(t_conf *conf, int a, int q);
char		*get_next_line_bonus(int fd);
t_pos_en	enemy_pos_bonus(char **map);
void		set_enemy(char **map);
t_pos_z		zero_pos_bonus(char **map);
int			enemy_move_bonus(void *param);
void		game_img_1_bonus(t_conf *conf);
void		img_to_win_enemy_bonus(t_conf *conf, int a, int q);

#endif
