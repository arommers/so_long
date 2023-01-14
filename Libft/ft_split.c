/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 14:25:35 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/04 15:35:14 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	ft_get_rows(char const *s, char c)
{
	int	rows;
	int	i;

	rows = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			rows++;
		while (s[i] && s[i] != c)
				i++;
	}
	return (rows);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*wordstart;
	int		i;

	new = (char **)malloc(sizeof(char *) * (ft_get_rows(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			wordstart = (char *)s;
			while (*s != c && *s)
				s++;
			new[i] = ft_substr(wordstart, 0, s - wordstart);
			if (!**new)
				return (ft_free(new));
			i++;
		}
		else
			s++;
	}
	new[i] = NULL;
	return (new);
}

/*int	main(void)
{
	char **array;
	char const s[] = "Bulbasaur is the best";
	char c = ' ';
	int	i;
	array = ft_split(s, c);
	printf("%d\n", ft_get_rows(s, c));
	//printf("%c", **ft_split(s, c));
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}*/