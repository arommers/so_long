 /* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/03 12:58:45 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	error_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	check_map_shape(char **grid)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(grid[i]);
	if (len < 3)
		error_message("Map is not big enough");
	i++;
	while(grid[i])
	{
		if (ft_strlen(grid[i]) != len)
			error_message("Map is no rectangle");
		i++;
	}
	if (i < 3)
			error_message("Map is not big enough");
}

// int	**check_map_validity(char **grid)
// {
// 	check_map_shape(grid);
// }