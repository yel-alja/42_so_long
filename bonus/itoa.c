/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:10:20 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/26 10:22:36 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_count_digits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	i;

	i = (long)n;
	len = ft_count_digits(i);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	if (i < 0)
	{
		i *= -1;
		ptr[0] = '-';
	}
	while (len > 0 && i > 0)
	{
		ptr[len - 1] = i % 10 + '0';
		i /= 10;
		len--;
	}
	len = ft_count_digits(n);
	ptr[len] = '\0';
	return (ptr);
}
