/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:47:29 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/28 15:19:53 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	put_image_to_window(char **map, t_game game, int flag)
{
	int			i;
	int			j;
	t_position	index;

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
			j++;
		}
		i++;
	}
}

void	moves(t_game *game, int flag, char **map)
{
	if (flag == DOWN && map[game->p.x + 1][game->p.y] != '1')
	{
		map[game->p.x][game->p.y] = '0';
		map[game->p.x + 1][game->p.y] = 'P';
		put_image_to_window(game->map, *game, DOWN);
		ft_putnbr(game->moves++);
		write(1, "\n", 1);
	}
	if (flag == RIGHT && map[game->p.x][game->p.y + 1] != '1')
	{
		map[game->p.x][game->p.y] = '0';
		map[game->p.x][game->p.y + 1] = 'P';
		put_image_to_window(game->map, *game, RIGHT);
		ft_putnbr(game->moves++);
		write(1, "\n", 1);
	}
	if (flag == LEFT && map[game->p.x][game->p.y - 1] != '1')
	{
		map[game->p.x][game->p.y] = '0';
		map[game->p.x][game->p.y - 1] = 'P';
		put_image_to_window(game->map, *game, LEFT);
		ft_putnbr(game->moves++);
		write(1, "\n", 1);
	}
}

void	move_player(t_game *game, int flag)
{
	char	**map;

	map = game->map;
	if (flag == UP && map[game->p.x - 1][game->p.y] != '1')
	{
		map[game->p.x][game->p.y] = '0';
		map[game->p.x - 1][game->p.y] = 'P';
		put_image_to_window(game->map, *game, UP);
		ft_putnbr(game->moves++);
		write(1, "\n", 1);
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
	mlx_loop(game.init);
}
