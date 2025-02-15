/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:23:12 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/15 09:08:15 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
	res = ft_split(map, '\n');
	check_array(res, map);
	check_map(res, map);
	free_s(res);
	free(map);
}
