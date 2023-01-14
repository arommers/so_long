/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 13:36:02 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:44:34 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}

/*
int	main(void)
{
	char	*str;
	int		i;

	str = "bulbasaur";
	i = 'f';
	printf("%s\n", ft_strrchr(str, i));
	printf("%s\n", strrchr(str, i));
	return (0);
}
*/