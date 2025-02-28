/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:01:33 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/27 11:07:35 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_game3(t_game *game, int x, int y)
{
	game->image_enemy3 = mlx_xpm_file_to_image(game->init, ENEMY3, &x, &y);
	if (!game->image_enemy3)
		free_game(game, 1);
}

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
	game->image_enemy0 = mlx_xpm_file_to_image(game->init, ENEMY0, &x, &y);
	if (!game->image_enemy0)
		free_game(game, 1);
	game->image_enemy1 = mlx_xpm_file_to_image(game->init, ENEMY1, &x, &y);
	if (!game->image_enemy1)
		free_game(game, 1);
	game->image_enemy2 = mlx_xpm_file_to_image(game->init, ENEMY2, &x, &y);
	if (!game->image_enemy2)
		free_game(game, 1);
	init_game3(game, x, y);
}

void	init_game(t_game *game, char **map)
{
	int	x;
	int	y;

	game->map = map;
	game->height = count_line(map);
	game->width = ft_strlen(map[1]);
	game->init = mlx_init();
	game->enemy = enemy_position(map);
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
	game->moves = 1;
}

void	free_game2(t_game *game, int flag)
{
	if (game->image_enemy0)
		mlx_destroy_image(game->init, game->image_enemy0);
	if (game->image_enemy1)
		mlx_destroy_image(game->init, game->image_enemy1);
	if (game->image_enemy2)
		mlx_destroy_image(game->init, game->image_enemy2);
	if (game->image_enemy3)
		mlx_destroy_image(game->init, game->image_enemy3);
	if (game->image_enemy4)
		mlx_destroy_image(game->init, game->image_enemy4);
	if (game->image_enemy5)
		mlx_destroy_image(game->init, game->image_enemy5);
	if (game->init)
		mlx_destroy_display(game->init);
	if (game->init)
		free(game->init);
	free_s(game->map);
	exit(flag);
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
	free_game2(game, flag);
}
