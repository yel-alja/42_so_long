/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:23:21 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/16 20:27:57 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(char **map, char *str)
{
	free_s(map);
	if (str)
		free(str);
	write(2, "Error: invalid map\n", 19);
	exit(1);
}
char	*read_map(char *str)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[1000];
	char	*map;

	fd = open(str, O_RDONLY);
	if(fd == -1)
	{
		write(2 , "Error: can't open file\n" ,23);
		exit(1);
	}
	bytes_read = 1;
	map = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 999);
		buffer[bytes_read] = '\0';
		map = ft_strjoin(map, buffer);
	}
	return (map);
}

int	check_array(char **str, char *s)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	len = ft_strlen(str[0]);
	while (str[i])
	{
		j = 0;
		if (i == 0 || str[i + 1] == NULL)
		{
			while (str[i][j])
			{
				if (str[i][j] != '1')
					free_exit(str, s);
				j++;
			}
		}
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1'
			|| ft_strlen(str[i]) != len)
			free_exit(str, s);
		i++;
	}
	return (1);
}

void	check_map(char **map, char *str)
{
	int		i;
	int		j;
	char	seen[82] = {0};

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != '1' && map[i][j] != '0')
				free_exit(map, str);
			if (map[i][j] == 'E' || map[i][j] == 'P')
			{
				if (seen[(unsigned char)map[i][j]] == 0)
					seen[(unsigned char)map[i][j]] = 1;
				else
					free_exit(map, str);
			}
			j++;
		}
		i++;
	}
	if (seen['E'] == 0 || seen['P'] == 0)
		free_exit(map, str);
}
