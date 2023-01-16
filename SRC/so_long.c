/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/16 15:10:04 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_var(t_game *data)
{
	data->width = 0;
	data->height = 0;
	data->steps = 0;
}

int	main(argc, **argv)
{
	t_game	data;

	input_check(argc, argv);
	init_var(&data);
	make_array(argv[1], &data);
	check_map(&data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		ft_error();
	fill_background(&data);
	fill_map(&data)
	mlx_loop(data->mlx);
	mlx_delete_texture(texture);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
