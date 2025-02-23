/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:47:29 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/23 08:48:44 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, char **map)
{
	int	x;

	x = 32;
	game->map = map;
	game->height = count_line(map);
	game->width = ft_strlen(map[1]);
	game->init = mlx_init();
	game->window = mlx_new_window(game->init, game->width * 32, game->height
			* 32, "so_long");
	game->image_wall = mlx_xpm_file_to_image(game->init, WALL, &x, &x);
	game->image_bg = mlx_xpm_file_to_image(game->init, BACKGROUND, &x, &x);
	game->image_player_u = mlx_xpm_file_to_image(game->init, PLAYER_U, &x, &x);
	game->image_player_d = mlx_xpm_file_to_image(game->init, PLAYER_D, &x, &x);
	game->image_player_l = mlx_xpm_file_to_image(game->init, PLAYER_L, &x, &x);
	game->image_player_r = mlx_xpm_file_to_image(game->init, PLAYER_R, &x, &x);
	game->image_exit = mlx_xpm_file_to_image(game->init, EXIT, &x, &x);
	game->image_collect = mlx_xpm_file_to_image(game->init, COLLECT, &x, &x);
	game->position = player_position(map);
}
// void put_image_to_window2(char **map , t_game game , int flag)
// {

// }


void	put_image_to_window(char **map, t_game game , int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(game.init, game.window, game.image_wall,
					j * 32, i * 32);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(game.init, game.window, game.image_bg, j
					* 32, i * 32);
			else if (map[i][j] == 'P' && flag == LEFT)
				mlx_put_image_to_window(game.init, game.window,
					game.image_player_l, j * 32, i * 32);
			else if (map[i][j] == 'P' && flag == RIGHT)
				mlx_put_image_to_window(game.init, game.window,
					game.image_player_r, j * 32, i * 32);
else if (map[i][j] == 'P' && flag == DOWN)
				mlx_put_image_to_window(game.init, game.window,
					game.image_player_d, j * 32, i * 32);
else if (map[i][j] == 'P' && flag == UP)
				mlx_put_image_to_window(game.init, game.window,
					game.image_player_u, j * 32, i * 32);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(game.init, game.window, game.image_exit,
					j * 32, i * 32);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game.init, game.window,
					game.image_collect, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
void	free_game(t_game *game)
{
	free(game->image_bg); //-------===================================----free imgs
	exit(0);
	return ;
}

void	move_player(t_game *game, int flag)
{
	char		**map;
	static int	i = 0;

	map = game->map;
	if (flag == UP && map[game->position.x - 1][game->position.y] != '1')
	{
		map[game->position.x][game->position.y] = '0';
		map[game->position.x - 1][game->position.y] = 'P';
	put_image_to_window(game->map, *game , UP);
		ft_putnbr(i++);
		write(1, "\n", 1);
	}
	if (flag == DOWN && map[game->position.x + 1][game->position.y] != '1')
	{
		map[game->position.x][game->position.y] = '0';
		map[game->position.x + 1][game->position.y] = 'P';
	put_image_to_window(game->map, *game , DOWN);
		ft_putnbr(i++);
		write(1, "\n", 1);
	}
	if (flag == RIGHT && map[game->position.x][game->position.y + 1] != '1')
	{
		map[game->position.x][game->position.y] = '0';
		map[game->position.x][game->position.y + 1] = 'P';
	put_image_to_window(game->map, *game , RIGHT);
		ft_putnbr(i++);
		write(1, "\n", 1);
	}
	if (flag == LEFT && map[game->position.x][game->position.y - 1] != '1' )
	{
		map[game->position.x][game->position.y] = '0';
		map[game->position.x][game->position.y - 1] = 'P';
	put_image_to_window(game->map, *game , LEFT);
		ft_putnbr(i++);
		write(1, "\n", 1);
	}
	game->position = player_position(game->map);
}

int	key_handler(int keyhook, t_game *game)
{
	if (keyhook == UP)
		move_player(game, UP);
	if (keyhook == RIGHT)
		move_player(game, RIGHT);
	if (keyhook == LEFT)
		move_player(game, LEFT);
	if (keyhook == DOWN)
		move_player(game, DOWN);
	if (keyhook == ESC)
		free_game(game);
	return (0);
}

int	mouse_handler(int mousehook, t_game *game)
{
	(void)mousehook;
	(void)game;
	// free_game(game);
	exit(1);
}

void	mlx_manager(char **map)
{
	t_game	game;
	int		i;
	int		j;

	game = (t_game){0};
	i = 0;
	j = 0;
	init_game(&game, map);
	put_image_to_window(map, game , LEFT);
	mlx_key_hook(game.window, key_handler, &game);
	mlx_hook(game.window, 17, 0, mouse_handler, &game);
	mlx_loop(game.init);
}
