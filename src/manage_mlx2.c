/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:01:33 by yel-alja          #+#    #+#             */
/*   Updated: 2025/03/13 14:02:11 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game2(t_game *game, int x, int y)
{
	game->image_player_d = mlx_xpm_file_to_image(game->init, PLAYER_D, &x, &y);
	if (!game->image_player_d)
		free_game(game, 1);
	game->image_player_l = mlx_xpm_file_to_image(game->init, PLAYER_L, &x, &y);
	if (!game->image_player_l)
		free_game(game, 1);
	game->image_player_r = mlx_xpm_file_to_image(game->init, PLAYER_R, &x, &y);
	if (!game->image_player_r)
		free_game(game, 1);
	game->image_exit = mlx_xpm_file_to_image(game->init, EXIT, &x, &y);
	if (!game->image_exit)
		free_game(game, 1);
	game->image_collect = mlx_xpm_file_to_image(game->init, COLLECT, &x, &y);
	if (!game->image_collect)
		free_game(game, 1);
	game->moves = 1;
}

void	init_game(t_game *game, char **map)
{
	int	x;
	int	y;

	game->map = map;
	game->height = count_line(map);
	game->width = ft_strlen(map[1]);
	game->init = mlx_init();
	if (!game->init)
		free_game(game, 1);
	game->window = mlx_new_window(game->init, game->width * 32, game->height
			* 32, "so_long");
	if (!game->window)
		free_game(game, 1);
	game->image_wall = mlx_xpm_file_to_image(game->init, WALL, &x, &y);
	if (!game->image_wall)
		free_game(game, 1);
	game->image_bg = mlx_xpm_file_to_image(game->init, BACKGROUND, &x, &y);
	if (!game->image_bg)
		free_game(game, 1);
	game->image_player_u = mlx_xpm_file_to_image(game->init, PLAYER_U, &x, &y);
	if (!game->image_player_u)
		free_game(game, 1);
	init_game2(game, x, y);
	game->p = player_position(map);
	game->exit = exit_position(map);
}

void	free_game(t_game *game, int flag)
{
	if (game->image_bg)
		mlx_destroy_image(game->init, game->image_bg);
	if (game->image_wall)
		mlx_destroy_image(game->init, game->image_wall);
	if (game->image_collect)
		mlx_destroy_image(game->init, game->image_collect);
	if (game->image_exit)
		mlx_destroy_image(game->init, game->image_exit);
	if (game->image_player_d)
		mlx_destroy_image(game->init, game->image_player_d);
	if (game->image_player_u)
		mlx_destroy_image(game->init, game->image_player_u);
	if (game->image_player_l)
		mlx_destroy_image(game->init, game->image_player_l);
	if (game->image_player_r)
		mlx_destroy_image(game->init, game->image_player_r);
	if (game->window)
		mlx_destroy_window(game->init, game->window);
	if (game->init)
		mlx_destroy_display(game->init);
	if (game->init)
		free(game->init);
	free_s(game->map);
	exit(flag);
}

void	check_win(t_game game)
{
	if (counter(game.map) == 0
		&& game.map[game.p.x][game.p.y] == game.map[game.exit.x][game.exit.y])
	{
		write(1, "Congratulation you won!\n", 24);
		free_game(&game, 0);
	}
}

int	key_handler(int keyhook, t_game *game)
{
	if (keyhook == UP || keyhook == W)
		move_player(game, UP);
	if (keyhook == RIGHT || keyhook == D)
		move_player(game, RIGHT);
	if (keyhook == LEFT || keyhook == A)
		move_player(game, LEFT);
	if (keyhook == DOWN || keyhook == S)
		move_player(game, DOWN);
	if (keyhook == ESC)
		free_game(game, 0);
	check_win(*game);
	return (0);
}
