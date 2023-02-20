/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_various.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:28:46 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/20 10:50:48 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(int i)
{
	write (1, &i, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_int(int n)
{
	char	*str;
	int		count;

	str = ft_itoa(n);
	if (str == NULL)
		return (0);
	count = ft_strlen(str);
	ft_print_str(str);
	free(str);
	return (count);
}
