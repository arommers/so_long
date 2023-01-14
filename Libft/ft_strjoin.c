/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:20:45 by arommers      #+#    #+#                 */
/*   Updated: 2022/10/26 08:44:05 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h> 

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;
	char	*new;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen (s2);
	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (!new)
		return (NULL);
	while (i < len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < len_s2)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
