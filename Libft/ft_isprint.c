/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:39:31 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:08:30 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	ft_isprint(int c);

int	main(void)
{
	int	i;

	i = 55;
	printf("%d\n", ft_isprint(i));
	printf("%d\n", isprint(i));
	return (0);
}
*/