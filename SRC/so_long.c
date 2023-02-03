/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/03 12:58:45 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	t_img		*images;

	if (argc != 2)
		return (0);
	game = initialize_data(argv[1]);
	game->mlx = mlx_init(game->width * PIXELS,
			game->height * PIXELS, "test", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	images = initialize_img_struct(game->mlx);
	game->img = images;
	fill_background(game);
	render_map(game);
	mlx_key_hook(game->mlx, &move_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}
