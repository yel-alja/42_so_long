/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:22:30 by yel-alja          #+#    #+#             */
/*   Updated: 2025/03/03 14:02:29 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	mouse_handler(t_game *game)
{
	free_game(game, 0);
	return (0);
}
