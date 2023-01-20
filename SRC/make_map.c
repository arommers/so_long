/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:51:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/20 15:04:46 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

t_game	*make_array(char *map, t_game *data)
{
	int		fd;
	char	*line;
	char	*line_joined;
	int		i;
	
	i = 0;
	data->map->width = 0;
	data->map->height = 0;

	line_joined = ft_calloc(1, 1);
	fd = open(map, O_RDONLY);

	while (1)
	{
		line = get_next_line (fd);
		if (line)
		{
			line_joined = ft_strjoin(line_joined, line); 
		}
		else
			break ;
	}
	char **map_rows;
	
	map_rows = ft_split(line_joined, '\n');
	printf("\nc: %c\n", map_rows[1][0]);
	int	x;
	int	y;
	x = 0;
	y = 0;
	while (map_rows[y])
	{
		x = 0;
		while (map_rows[y][x])
		{
			printf("%c", map_rows[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	data->map->width = x;
	data->map->height = y;
	close(fd);
	return(data);
}

void	fill_background(t_game *data)
{
	size_t		x;
	size_t		y;
	size_t		i;
	size_t		j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			mlx_image_to_window(data->mlx, data->play->player_i, i, j);
			i += 64;
			x++;
		}
		i = 0;
		j += 64;
		y++;
	}
}