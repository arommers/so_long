/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:51:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/19 12:30:06 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	image_select(t_game *data, size_t y, size_t x)
{
	size_t	img_size;

	img_size = 32;
	if (data->grid[y][x] == '1')
		if (mlx_image_to_window(data->mlx, data->img->bush,
				x * PIXELS, y * PIXELS) < 0)
			error_message("Failed to put image to window");
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window(data->mlx, data->img->rupee,
				x * PIXELS + img_size / 2, y * PIXELS + img_size / 2) < 0)
			error_message("Failed to put image to window");
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window(data->mlx, data->img->link,
				x * PIXELS, y * PIXELS) < 0)
			error_message("Failed to put image to window");
	if (data->grid[y][x] == 'E')
		if (mlx_image_to_window(data->mlx, data->img->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			error_message("Failed to put image to window");
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
			if (mlx_image_to_window(data->mlx, data->img->grass,
					x * PIXELS, y * PIXELS) < 0)
				error_message("Failed to put image to window");
			x++;
		}
		y++;
	}
}

void	put_enemies(t_game *data)
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
			if (data->grid[y][x] == 'X')
				if (mlx_image_to_window(data->mlx, data->img->enemy,
						x * PIXELS, y * PIXELS) < 0)
					error_message("Failed to put image to window");
			x++;
		}
		y++;
	}
}

void	render_map(t_game *data)
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
			image_select(data, y, x);
			x++;
		}
		y++;
	}
}
