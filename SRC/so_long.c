/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/19 15:20:23 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_var(t_game *data)
{
	data->width = 0;
	data->height = 0;
	data->steps = 0;
}

int	main(int argc, char **argv)
{
	t_game	*data;

	data = (t_game *) malloc(sizeof(t_game));
	if (!data)
		return (0);
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		return (0);
	data->img = (t_img *) malloc(sizeof(t_img));
	if (!data->img)
		return (0);
	data->play = (t_play *) malloc(sizeof(t_play));
	if (!data->play)
		return (0);
	if (argc != 2)
		return (0);
	init_var(data);
	//check_map(&data);
	make_array(argv[1], data);
	data->mlx = mlx_init(data->map->width * 64, data->map->height * 64, "so_long", true);
	data->play->player_t = mlx_load_png("./Sprites/gras.png");
	data->play->player_i = mlx_texture_to_image(data->mlx, data->play->player_t);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	mlx_image_to_window(data->mlx, data->play->player_i, 0, 0);
	//fill_background(&data);
	//fill_map(&data);
	mlx_loop(data->mlx);
	//mlx_delete_texture(texture);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
