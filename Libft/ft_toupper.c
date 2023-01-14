/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:46:03 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:50:24 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*int	ft_toupper(int c);

int	main(void)
{
	int	i;

	i = 'Z';
	printf("%d\n", ft_toupper(i));
	printf("%d\n", toupper(i));
	return (0);
}
*/