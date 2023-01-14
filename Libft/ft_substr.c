/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 13:39:01 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:48:08 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		j;
	size_t		i;
	size_t		size;
	char		*str;

	size = ft_strlen(s);
	if (size <= len)
		len = size;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
/*int	main(void)
{
	char const s[] = "hello world";
	unsigned int	start = 7;
	size_t	len = 2;
	printf("%s", ft_substr(s,start,len));
	return (0);
}*/