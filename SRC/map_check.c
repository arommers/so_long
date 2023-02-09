/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/09 11:04:01 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	check_map_content(char *map)
{
	int	player;
	int	exit;
	int	rupees;
	int	i;

	player = 0;
	exit = 0;
	rupees = 0;
	i = 0;
	while (map[i++])
	{
		if (map[i] == 'P')
			player++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'C')
			rupees++;
		else
			check_invalid_content(map);
	}
	if (player != 1 || exit != 1 || rupees < 1)
	{
		error_message("Map content is not valid");
	}
}

void	check_invalid_content(char *map)
{
	if (!(ft_strchr("PEC01\n", *map)))
	{
		error_message("Map contains invalid characters");
	}
}

void	check_horo(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->grid[0][i])
	{
		if (game->grid[0][i] != '1')
			error_message("The map is not surround by walls");
		if (game->grid[game->height -1][0] != '1')
			error_message("The map is not surrounded by walls");
		i++;
	}
}

void	check_vert(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->grid[i])
	{
		if (game->grid[i][0] != '1')
			error_message("The map is not surrounded by walls");
		if (game->grid[i][game->width -1] != '1')
			error_message("The map is not surrounded by walls");
		i++;
	}
}

void	check_walls(t_game *game)
{
	check_horo(game);
	check_vert(game);
}

void	check_empty_lines(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && (map[i + 1]) == '\n')
			error_message("Map contains empty lines");
		i++;
	}
}

void	check_file_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4))
		error_message("Please provide a .ber file");
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
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
			error_message("Map is not a rectangle");
		i++;
	}
	if (i < 3)
		error_message("Map is not big enough");
}
