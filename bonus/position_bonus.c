/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:22:30 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/27 18:50:45 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_position	exit_position(char **str)
{
	t_position	exit;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
			{
				exit.x = i;
				exit.y = j;
			}
			j++;
		}
		i++;
	}
	return (exit);
}

t_position	enemy_position(char **str)
{
	t_position	enemy;
	int			i;
	int			j;

	enemy = (t_position){0};
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'B')
			{
				enemy.x = i;
				enemy.y = j;
			}
			j++;
		}
		i++;
	}
	return (enemy);
}

int	mouse_handler(t_game *game)
{
	free_game(game, 0);
	return (0);
}

void	full_window2(t_game game, char c, t_position index)
{
	char		*str;
	static int	id;
	static int count;
	int total_enemy;

	total_enemy = counter(game.map , 'B');
	if (c == 'B')
	{
		id += (count % total_enemy);
		if (id % 3 == 0)
			mlx_put_image_to_window(game.init, game.window, game.image_enemy0,
				index.y * 32, index.x * 32);
		if (id % 3 == 1)
			mlx_put_image_to_window(game.init, game.window, game.image_enemy1,
				index.y * 32, index.x * 32);
		if (id % 3 == 2)
			mlx_put_image_to_window(game.init, game.window, game.image_enemy2,
				index.y * 32, index.x * 32);
		if (id % 3 == 3)
			mlx_put_image_to_window(game.init, game.window, game.image_enemy3,
				index.y * 32, index.x * 32);
		if (count % (50 * total_enemy) == 0)
			id++;
		id -= (count % total_enemy);

		count++;
	}
	str = ft_itoa(game.moves);
	mlx_string_put(game.init, game.window, 11, 19, 0X53C8F1, str);
	free(str);
}
