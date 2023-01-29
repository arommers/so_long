/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:51:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/29 13:27:05 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

char	*read_map(char *map)
{
	char	*line;
	char	*line_joined;
	int		fd;

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
	close (fd);
	return (free(line), line_joined);
}

size_t	row_count(char **grid)
{
	size_t	y;

	y = 0;
	while (grid[y])
		y++;
	return (y);
}

t_game	*initialize_game_struct(char **grid)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->width = ft_strlen(grid[0]);
	game->height = row_count(grid);
	game->grid = grid;
	return (game);
}

t_game	*initialize_data(char *map)
{
	char	*map_as_str;
	char	**map_as_array;
	t_game	*data;

	map_as_str = read_map(map);
	map_as_array = ft_split(map_as_str, '\n');
	data = initialize_game_struct(map_as_array);
	return (data);
}

t_game	*update_game_struct(mlx_t *mlx, t_img *images, t_game *game)
{
	game->mlx = mlx;
	game->img = images;
	return (game);
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
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_image_to_window(data->mlx, data->img->Bush, i, j);
			i += PIXELS;
			x++;
		}
		i = 0;
		j += PIXELS;
		y++;
	}
}
