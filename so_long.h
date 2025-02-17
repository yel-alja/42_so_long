/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:26:09 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/16 13:16:26 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h> 			//rm this
# include <stdlib.h>
# include <unistd.h>

typedef struct s_position
{
	int x;
	int y;
}		t_position;

void	free_exit(char **map, char *str);
void	free_s(char **c);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	check_map(char **map, char *str);
int		check_array(char **str, char *s);
char	*read_map(char *str);


//test
t_position player_position(char **str);
void validate_map(char **map);
int count_line(char **arr);

#endif
