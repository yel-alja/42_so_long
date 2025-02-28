/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:23:21 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/28 18:35:59 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_exit(char **map)
{
	free_s(map);
	write(2, "Error: invalid map\n", 19);
	exit(1);
}

void	check_ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b' || str[i
			- 4] != '.')
	{
		write(2, "Error: map's file must be <.ber>\n", 33);
		exit(1);
	}
}

char	*read_map(char *str)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[1000];
	char	*map;

	check_ber(str);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: can't open file\n", 23);
		exit(1);
	}
	bytes_read = 1;
	map = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 999);
		buffer[bytes_read] = '\0';
		map = ft_strjoin(map, buffer);
		if (!map)
			(free(map), exit(1));
	}
	close(fd);
	return (map);
}

int	check_array(char **str)
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
					free_exit(str);
				j++;
			}
		}
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1'
			|| ft_strlen(str[i]) != len)
			free_exit(str);
		i++;
	}
	return (1);
}

void	check_map(char **map)
{
	int			i;
	int			j;
	static char	seen[82];

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'B')
				free_exit(map);
			if (map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'C')
			{
				if (seen[(unsigned char)map[i][j]] == 0)
					seen[(unsigned char)map[i][j]] = 1;
				else if ((seen[(unsigned char)map[i][j]] == 1)
					&& (map[i][j] == 'P' || map[i][j] == 'E'))
					free_exit(map);
			}
		}
	}
	if (seen['E'] == 0 || seen['P'] == 0 || seen['C'] == 0)
		free_exit(map);
}
