/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 11:55:43 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/09 15:51:29 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_path(t_game *temp, size_t y, size_t x, size_t C)
{
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'E')
		return (C == 0);
	if (temp->grid[y][x] == 'C')
	{
		C--;
		temp->grid[y][x] = '0';
	}
	else
		temp->grid[y][x] = '1';
	if (check_path(temp, y + 1, x, C))
		return (1);
	if (check_path(temp, y - 1, x, C))
		return (1);
	if (check_path(temp, y, x + 1, C))
		return (1);
	if (check_path(temp, y, x - 1, C))
		return (1);
	return (0);
}

void	flood_fill(t_game *game)
{
	t_game	temp;
	size_t	i;

	temp.height = game->height;
	temp.width = game->width;
	temp.rupees = game->rupees;
	temp.link_x = game->link_x;
	temp.link_y = game->link_y;
	temp.grid = (char **)malloc(temp.height * sizeof(char *));
	if (!temp.grid)
		error_message("Memory allocation failed");
	i = 0;
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	if (!(check_path(&temp, temp.link_y, temp.link_x, temp.rupees)))
		error_message("No valid path available");
	free(temp.grid);
}
