/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_structs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 14:53:00 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/09 13:09:03 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	check_map_content(map_as_str);
	check_empty_lines(map_as_str);
	map_as_array = ft_split(map_as_str, '\n');
	check_map_shape(map_as_array);
	data = initialize_game_struct(map_as_array);
	flood_fill(data);
	check_walls(data);
	free (map_as_str);
	return (data);
}

t_img	*initialize_img_struct(mlx_t *mlx)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_grass_texture(mlx, assets);
	assets = load_bush_texture(mlx, assets);
	assets = load_rupee_texture(mlx, assets);
	assets = load_link_texture(mlx, assets);
	assets = load_link_up(mlx, assets);
	assets = load_link_down(mlx, assets);
	assets = load_link_right(mlx, assets);
	assets = load_link_left(mlx, assets);
	assets = load_exit_closed(mlx, assets);
	assets = load_exit_open(mlx, assets);
	return (assets);
}
