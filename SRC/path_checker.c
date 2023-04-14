/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 11:55:43 by arommers      #+#    #+#                 */
/*   Updated: 2023/04/14 09:43:48 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	check_path(t_game *temp, size_t y, size_t x)
{
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'C')
		temp->rupees--;
	if (temp->grid[y][x] == 'E')
	{
		temp->exit_x = 1;
		return (0);
	}
	temp->grid[y][x] = '1';
	if (check_path(temp, y + 1, x))
		return (1);
	if (check_path(temp, y - 1, x))
		return (1);
	if (check_path(temp, y, x + 1))
		return (1);
	if (check_path(temp, y, x - 1))
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
	temp.exit_x = 0;
	temp.grid = (char **)malloc(temp.height * sizeof(char *));
	if (!temp.grid)
		error_message("Memory allocation failed");
	i = 0;
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	check_path(&temp, temp.link_y, temp.link_x);
	if (!(temp.exit_x == 1 && temp.rupees == 0))
		error_message("No valid path available");
	free_grid(temp.grid, temp.height);
}
