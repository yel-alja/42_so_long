/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:20:01 by yel-alja          #+#    #+#             */
/*   Updated: 2025/03/13 13:50:22 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	player_position(char **str)
{
	t_position	player;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				player.x = i;
				player.y = j;
			}
			j++;
		}
		i++;
	}
	return (player);
}

char	**cpy_arr(char **arr)
{
	char	**map;
	int		i;
	int		j;

	map = malloc((count_line(arr) + 1) * sizeof(char *));
	if (!map)
		(free_s(arr), exit(1));
	i = 0;
	while (arr[i])
	{
		j = 0;
		map[i] = malloc(ft_strlen(arr[i]) + 1);
		if (!map)
			(free_s(arr), free_s(map), exit(1));
		while (arr[i][j])
		{
			map[i][j] = arr[i][j];
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	flood_fill(char **tmp, int x, int y)
{
	if (tmp[x][y] == '1' || tmp[x][y] == 'V')
		return ;
	tmp[x][y] = 'V';
	flood_fill(tmp, x - 1, y);
	flood_fill(tmp, x + 1, y);
	flood_fill(tmp, x, y - 1);
	flood_fill(tmp, x, y + 1);
}

void	is_valid(char **map, char **ori)
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
			if (map[i][j] != 'V' && map[i][j] != '1' && map[i][j] != '0')
			{
				write(2, "Error:\ninvalid map\n", 19);
				free_s(map);
				free_s(ori);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
