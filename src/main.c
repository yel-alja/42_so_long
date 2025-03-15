/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:23:12 by yel-alja          #+#    #+#             */
/*   Updated: 2025/03/13 13:50:32 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(char **map)
{
	t_position	player;
	char		**tmp;

	tmp = cpy_arr(map);
	player = player_position(tmp);
	flood_fill(tmp, player.x, player.y);
	is_valid(tmp, map);
	free_s(tmp);
}

void	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '\n' || (str[i] == '\n' && str[i + 1] == '\n'))
		{
			free(str);
			write(2, "Error:\ninvalid map\n", 19);
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*map;
	char	**res;

	if (ac != 2)
	{
		write(1, "the arguments must look like : ./so_long <map PATH>\n", 52);
		exit(1);
	}
	map = read_map(av[1]);
	check_str(map);
	res = ft_split(map, '\n');
	free(map);
	if (!res)
		return (1);
	check_walls(res);
	check_map(res);
	validate_map(res);
	mlx_manager(res);
	free_s(res);
}
