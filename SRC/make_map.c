/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:51:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/02 16:46:35 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

size_t	count_rupees(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	i = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'C')
			{
				i += 1;
			}
			x++;
		}
		y++;
	}
	return (i);
}

char	*read_map(char *map)
{
	char	*line;
	char	*line_joined;
	int		fd;

	fd = open(map, O_RDONLY);
	line_joined = ft_calloc(1, 1);
	if (!line_joined)
		return (NULL);
	while (1)
	{
		line = get_next_line (fd);
		if (line)
		{
			line_joined = ft_strjoin(line_joined, line);
			free(line);
		}
		else
			break ;
	}
	close (fd);
	return (line_joined);
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
	game->steps = 0;
	game->rupees = count_rupees(game);
	game->link_x = get_link_pos(game, 'x');
	game->link_y = get_link_pos(game, 'y');
	game->exit_x = get_exit_pos (game, 'x');
	game->exit_y = get_exit_pos (game, 'y');
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
	free (map_as_str);
	return (data);
}

void	fill_background(t_game *data)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_image_to_window(data->mlx, data->img->grass, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
}

void	render_map(t_game *data)
{
	size_t		x;
	size_t		y;
	int			img_size;

	x = 0;
	y = 0;
	img_size = 32;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->grid[y][x] == '1')
				mlx_image_to_window(data->mlx, data->img->bush, x * PIXELS, y * PIXELS);
			if (data->grid[y][x] == 'C')
				mlx_image_to_window(data->mlx, data->img->rupee,
					x * PIXELS + img_size / 2, y * PIXELS + img_size / 2);
			if (data->grid[y][x] == 'P')
				mlx_image_to_window(data->mlx, data->img->link, x * PIXELS, y * PIXELS);
			if (data->grid[y][x] == 'E')
				mlx_image_to_window(data->mlx, data->img->exit_closed, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
}
