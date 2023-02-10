/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/10 16:25:30 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_invalid_content(char *map)
{
	if (!(ft_strchr("PEC01\n", *map)))
	{
		error_message("Map contains invalid characters");
	}
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
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
			error_message("Map is not a rectangle");
		i++;
	}
}
