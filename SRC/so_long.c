/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/20 10:39:48 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	t_img		*images;

	if (argc != 2)
		error_message("Jezus how hard is it? I told you I need just one file");
	check_file_extension(argv[1]);
	game = initialize_data(argv[1]);
	game->mlx = mlx_init(game->width * PIXELS,
			game->height * PIXELS, "so_long", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	images = initialize_img_struct(game->mlx);
	game->img = images;
	fill_background(game);
	render_map(game);
	put_enemies(game);
	string_to_screen(game);
	mlx_key_hook(game->mlx, &move_hook, game);
	mlx_loop_hook(game->mlx, &enemy_patrol, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
