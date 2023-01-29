/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/29 11:59:42 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	t_img		*images;
	mlx_t		*mlx;

	if (argc != 2)
		return (0);
	game = initialize_data(argv[1]);
	//check_map(&data);
	// game->mlx = ft_calloc(1, 1);
	mlx = mlx_init(game->width * PIXELS, game->height * PIXELS, "test", true);
	if (!game->mlx)
		printf("MLX = NULL");
	images = initialize_img_struct(mlx);
	update_game_struct(mlx, images, game);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	fill_background(game);
	// mlx_image_to_window(data->mlx, data->play->player_i, 0, 0);
	//fill_map(&data);
	mlx_loop(game->mlx);
	// mlx_delete_texture(texture);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
