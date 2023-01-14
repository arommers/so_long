/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:47:39 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:23:58 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
	{
		while (len > i)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len -1] = ((char *)src)[len -1];
			len--;
		}
	}
	return (dst);
}

/*int	main(void)
{
	char	dest[100] = "aaaa";
	const char	src[100] = "123";
	size_t	n = 2;
	printf("%s", ft_memmove(dest, src, n));
}*/
