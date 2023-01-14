/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:18:16 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:30:00 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	j;
	unsigned int	i;

	j = (unsigned char)c;
	i = 0;
	while (s[i] != '\0' && s[i] != j)
		i++;
	if (s[i] == j)
		return ((char *)s + i);
	return (0);
}

/*int	main(void)
{
	const char	*str;
	int			i;

	str = "bulbasaur";
	i = 's';
	printf("%s\n", ft_strchr(str, i));
	printf("%s\n", strchr(str, i));
	return (0);
}
*/