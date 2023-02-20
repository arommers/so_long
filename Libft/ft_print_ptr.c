/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_ptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 15:06:24 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/20 10:50:31 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_size(unsigned long int len)
{
	unsigned long int	i;

	i = 0;
	while (len != 0)
	{
		len = len / 16;
		i++;
	}
	return (i);
}

static int	ft_print_ptr(unsigned long n, char *s)
{
	char				*str;
	unsigned long int	count;
	int					i;

	count = hex_size(n);
	str = (char *)ft_calloc (sizeof(char), (count + 1));
	if (!str)
		return (0);
	while (count--)
	{
		str[count] = s[n % 16];
		n = n / 16;
	}
	ft_print_str(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ft_return_ptr(unsigned long int n, char *s)
{
	int	count;

	count = 0;
	count = count + write(1, "0x", 2);
	if (n == 0)
		count = count + write(1, "0", 1);
	else
		count = count + ft_print_ptr(n, s);
	return (count);
}
