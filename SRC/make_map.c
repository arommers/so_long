/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:51:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/19 15:11:13 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	make_array(char *map, t_game *data)
{
	int		fd;
	char	*line;

	data->map->width = 0;
	data->map->height = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line (fd);
	data->map->grid = ft_split(line, '\n');
	while (data->map->grid[0][data->map->width] != '\0')
		data->map->width++;
	while (data->map->grid[data->map->height])
		data->map->height++;
	close(fd);
	free(line);
}

// void	fill_map(t_game *data)
// {
	
// }
