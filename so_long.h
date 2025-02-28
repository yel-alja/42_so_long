/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:26:09 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/28 18:30:28 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL "textures/wall.xpm"
# define BACKGROUND "textures/background.xpm"
# define PLAYER_R "textures/player_right.xpm"
# define PLAYER_L "textures/player_left.xpm"
# define PLAYER_U "textures/player_up.xpm"
# define PLAYER_D "textures/player_down.xpm"
# define EXIT "textures/exit.xpm"
# define COLLECT "textures/collect.xpm"
# define ESC 65307
# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define D 100
# define W 119
# define S 115
# define A 97

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_game
{
	char		**map;
	void		*init;
	void		*window;
	int			height;
	int			width;
	t_position	p;
	t_position	exit;
	void		*image_wall;
	void		*image_bg;
	void		*image_player_u;
	void		*image_player_d;
	void		*image_player_l;
	void		*image_player_r;
	void		*image_exit;
	void		*image_collect;
	int			moves;
}				t_game;

void			free_exit(char **map);
void			free_s(char **c);
char			**ft_split(const char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *str);
void			check_map(char **map);
int				check_array(char **str);
char			*read_map(char *str);
t_position		player_position(char **str);
void			validate_map(char **map);
int				count_line(char **arr);
t_position		exit_position(char **str);
void			mlx_manager(char **map);
int				counter(char **map);
void			ft_putnbr(int nb);
void			init_game(t_game *game, char **map);
void			free_game(t_game *game, int flag);
void			check_win(t_game game);
int				mouse_handler(t_game *game);
int				key_handler(int keyhook, t_game *game);
void			move_player(t_game *game, int flag);
char			**cpy_arr(char **arr);
void			flood_fill(char **tmp, int x, int y);
void			is_valid(char **map, char **ori);
int				mouse_handler(t_game *game);
#endif
