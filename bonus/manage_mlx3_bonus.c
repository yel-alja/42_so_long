/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:53:46 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/27 08:23:14 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	check_win(*game, -1);
	return (0);
}

void	check_win(t_game game, int flag)
{
	char	**map;

	map = game.map;
	if (counter(game.map, 'C') == 0
		&& game.map[game.p.x][game.p.y] == game.map[game.exit.x][game.exit.y])
	{
		write(1, "Congratulation you won!\n", 24);
		free_game(&game, 0);
	}
	if (flag == LEFT && map[game.p.x][game.p.y - 1] == 'B')
		(write(1, "game over\n", 10), free_game(&game, 0));
	if (flag == RIGHT && map[game.p.x][game.p.y + 1] == 'B')
		(write(1, "game over\n", 10), free_game(&game, 0));
	if (flag == UP && map[game.p.x - 1][game.p.y] == 'B')
		(write(1, "game over\n", 10), free_game(&game, 0));
	if (flag == DOWN && map[game.p.x + 1][game.p.y] == 'B')
		(write(1, "game over\n", 10), free_game(&game, 0));
}
