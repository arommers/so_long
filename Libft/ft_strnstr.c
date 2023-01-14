/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 14:39:30 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:43:06 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (!needle[j])
					return ((char *)(haystack + i));
			}
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	big[] = "";
	char	small[] = "";
	size_t	c;

	c = 20;
	printf("%s\n", ft_strnstr(big, small, c));
	printf("%s\n", strnstr(big, small, c));
	return (0);
}
*/