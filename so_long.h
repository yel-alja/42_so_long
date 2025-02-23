/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:26:09 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/23 08:41:07 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h> //rm this
# include <stdlib.h>
# include <unistd.h>

# define WALL "pics/wall.xpm"
# define BACKGROUND "pics/background.xpm"
# define PLAYER_R "pics/player_right.xpm"
# define PLAYER_L "pics/player_left.xpm"
# define PLAYER_U "pics/player_up.xpm"
# define PLAYER_D "pics/player_down.xpm"
# define EXIT "pics/exit.xpm"
# define COLLECT "pics/collect.xpm"
#define ESC 65307
#define UP 65362
#define LEFT 65361
#define RIGHT 65363
#define DOWN 65364
typedef struct s_position
{
	int		x;
	int		y;
}			t_position;

typedef struct s_game
{
	char **map;
	void	*init;
	void	*window;
	int		height;
	int		width;
	t_position position;
	void	*image_wall;
	void	*image_bg;
	void	*image_player_u;
	void	*image_player_d;
	void	*image_player_l;
	void	*image_player_r;
	void	*image_exit;
	void	*image_collect;
}			t_game;

void		free_exit(char **map);
void		free_s(char **c);
char		**ft_split(const char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
void		check_map(char **map);
int			check_array(char **str);
char		*read_map(char *str);

// test
t_position	player_position(char **str);
void		validate_map(char **map);
int			count_line(char **arr);

void		mlx_manager(char **map);

void ft_putnbr(int nb);
#endif
