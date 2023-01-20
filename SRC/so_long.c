/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/20 15:08:54 by arommers      ########   odam.nl         */
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
	data = make_array(argv[1], data);
	data->mlx = ft_calloc(1, 1);
	data->mlx = mlx_init(data->map->width * 64, data->map->height * 64, "test", true);
	if (!data->mlx)
		printf("MLX = NULL");
	data->play->player_t = mlx_load_png("./Sprites/heart.png");
	data->play->player_i = mlx_texture_to_image(data->mlx, data->play->player_t);
	
	if (!data->mlx)
		exit(EXIT_FAILURE);
	fill_background(data);
	// mlx_image_to_window(data->mlx, data->play->player_i, 0, 0);
	//fill_map(&data);
	mlx_loop(data->mlx);
	// mlx_delete_texture(texture);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
