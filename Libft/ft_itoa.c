/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:50:17 by arommers      #+#    #+#                 */
/*   Updated: 2022/10/26 15:42:12 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static int	nbr_size(long int len)
{
	int	i;

	i = 0;
	if (len < 1)
	{
		len = len * -1;
		i++;
	}
	while (len > 0)
	{
		len = len / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				count;
	long int		i;

	i = n;
	count = nbr_size(i);
	str = (char *)ft_calloc (sizeof(char), (count + 1));
	if (!str)
		return (NULL);
	if (i < 0)
		i = i * -1;
	if (i == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (count--)
	{
		str[count] = i % 10 + '0';
		i = i / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// int main(void)
// {
// 	printf("%s\n", ft_itoa(-3251));
// 	//char *ret = ft_itoa(INT_MIN);
// 	//printf("%s\n", ret);
// 	//printf("%s\n", ft_itoa(-123456789));
// }