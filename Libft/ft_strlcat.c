/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:36:23 by arommers      #+#    #+#                 */
/*   Updated: 2022/10/19 18:25:53 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

/*Concatenate the string src to the end of dst. 
It will concatenate at most size - strlen(dst) - 1 bytes,
NUL-terminating the result */
/*
size_t	ft_strlcat(char *dst, const char *src, size_t size);

int	main(void)
{
	char		s1[50] = "hallo";
	const char	s2[] = " World";
	size_t		c;

	c = 5;
	printf("%zu\n", ft_strlcat(s1, s2, c));
	printf("%zu\n", strlcat(s1, s2, c));
	return (0);
}
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	b = 0;
	c = 0;
	while (dst[a] != '\0' && a < size)
		a++;
	while (src[b] != '\0' && a + b + 1 < size)
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a < size)
		dst[a + b] = '\0';
	while (src[c] != '\0')
		c++;
	return (a + c);
}
