/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:35:05 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:07:32 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	ft_isascii(int c);

int	main(void)
{
	int	i;

	i = 135;
	printf("%d\n", ft_isascii(i));
	printf("%d\n", isascii(i));
	return (0);
}*/