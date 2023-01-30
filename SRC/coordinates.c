/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordinates.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 14:53:00 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/30 15:03:32 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	get_link_pos(t_game *game, char c )
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'P')
			{
				if (c == game->grid[y][x])
					return (x);
				else
					return (y);
			}
			x++;
		}
	}
	return (0);
}

size_t	get_exit_pos(t_game *game, char c )
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'E')
			{
				if (c == game->grid[y][x])
					return (x);
				else
					return (y);
			}
			x++;
		}
	}
	return (0);
}
