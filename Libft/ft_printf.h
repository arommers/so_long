/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:48:01 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/15 12:53:24 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

int			ft_write_char(int i);
int			ft_printf(const char *s, ...);
int			ft_print_str(char *s);
int			ft_print_int(int n);
int			ft_print_unsigned(unsigned int i);
char		*ft_unsigned_itoa(unsigned int n);
int			ft_return_hex(unsigned int n, char *s);
int			ft_return_ptr(unsigned long n, char *s);
int			ft_converter(va_list ap, const char s);

#endif