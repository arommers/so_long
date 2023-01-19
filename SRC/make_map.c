/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:51:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/19 15:41:41 by arommers      ########   odam.nl         */
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
	printf("line: %s", line);
	data->map->grid = ft_split(line, '\n');
	// printf("Data: %s", ft_split(line, '\n'));
	// int	i;

	// i =	0;
	// while (data->map->grid[i] != '\0')
	// {
	// 	while (data->map->grid[i][data->map->width] != '\0')
	// 		data->map->width++;
	// 	data->map->height++;
	// 	i++;
	// }

	// int x, y;
	// x = 0;
	// y = 0;
	// printf("%c", data->map->grid[y][x]);

	// while (data->map->grid[y][x])
	// {
	// 	x = 0;
	// 	while (data->map->grid[y][x])
	// 	{
	// 		printf("%c", data->map->grid[y][x]);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// printf("\n");

	
	printf("%zu", data->map->height);
	close(fd);
	free(line);
}

// void	fill_map(t_game *data)
// {
	
// }
