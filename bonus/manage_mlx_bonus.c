/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:47:29 by yel-alja          #+#    #+#             */
/*   Updated: 2025/03/16 13:54:30 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	full_window(char c, t_game game, t_position index, int flag)
{
	if (c == '1')
		mlx_put_image_to_window(game.init, game.window, game.image_wall, index.y
			* 32, index.x * 32);
	else if (c == '0')
		mlx_put_image_to_window(game.init, game.window, game.image_bg, index.y
			* 32, index.x * 32);
	else if (c == 'P' && flag == LEFT)
		mlx_put_image_to_window(game.init, game.window, game.image_player_l,
			index.y * 32, index.x * 32);
	else if (c == 'P' && flag == RIGHT)
		mlx_put_image_to_window(game.init, game.window, game.image_player_r,
			index.y * 32, index.x * 32);
	else if (c == 'P' && flag == DOWN)
		mlx_put_image_to_window(game.init, game.window, game.image_player_d,
			index.y * 32, index.x * 32);
	else if (c == 'P' && flag == UP)
		mlx_put_image_to_window(game.init, game.window, game.image_player_u,
			index.y * 32, index.x * 32);
	else if (c == 'E')
		mlx_put_image_to_window(game.init, game.window, game.image_exit, index.y
			* 32, index.x * 32);
	else if (c == 'C')
		mlx_put_image_to_window(game.init, game.window, game.image_collect,
			index.y * 32, index.x * 32);
	full_window2(game, c, index);
}

void	put_image_to_window(char **map, t_game game, int flag)
{
	int			i;
	int			j;
	t_position	index;
	char		*str;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			index.x = i;
			index.y = j;
			full_window(map[i][j], game, index, flag);
			str = ft_itoa(game.moves);
			mlx_string_put(game.init, game.window, 11, 19, 0X53C8F1, str);
			free(str);
			j++;
		}
		i++;
	}
}

void	moves(t_game *game, int flag, char **map)
{
	if (flag == DOWN && map[game->p.x + 1][game->p.y] != '1')
	{
		check_win(*game, DOWN);
		map[game->p.x][game->p.y] = '0';
		map[game->p.x + 1][game->p.y] = 'P';
		put_image_to_window(game->map, *game, DOWN);
		game->moves++;
	}
	if (flag == RIGHT && map[game->p.x][game->p.y + 1] != '1')
	{
		check_win(*game, RIGHT);
		map[game->p.x][game->p.y] = '0';
		map[game->p.x][game->p.y + 1] = 'P';
		put_image_to_window(game->map, *game, RIGHT);
		game->moves++;
	}
	if (flag == LEFT && map[game->p.x][game->p.y - 1] != '1')
	{
		check_win(*game, LEFT);
		map[game->p.x][game->p.y] = '0';
		map[game->p.x][game->p.y - 1] = 'P';
		put_image_to_window(game->map, *game, LEFT);
		game->moves++;
	}
}

void	move_player(t_game *game, int flag)
{
	char	**map;

	map = game->map;
	if (flag == UP && map[game->p.x - 1][game->p.y] != '1')
	{
		check_win(*game, UP);
		map[game->p.x][game->p.y] = '0';
		map[game->p.x - 1][game->p.y] = 'P';
		put_image_to_window(game->map, *game, UP);
		game->moves++;
	}
	else if (flag == DOWN || flag == RIGHT || flag == LEFT)
		moves(game, flag, map);
	game->p = player_position(game->map);
	if (game->exit.x != game->p.x || game->exit.y != game->p.y)
	{
		game->map[game->exit.x][game->exit.y] = 'E';
		put_image_to_window(game->map, *game, 0);
	}
}

void	mlx_manager(char **map)
{
	t_game	game;

	game = (t_game){0};
	init_game(&game, map);
	put_image_to_window(map, game, LEFT);
	mlx_hook(game.window, 17, 0, mouse_handler, &game);
	mlx_hook(game.window, 2, 1, key_handler, &game);
	mlx_loop_hook(game.init, move_enemy, &game);
	mlx_loop(game.init);
}
