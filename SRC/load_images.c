/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_images.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/04/14 09:45:31 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_grass_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./Sprites/grass.png");
	if (!grass)
		error_message("Problem with loading png");
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
		error_message("Problem with texture to image");
	mlx_delete_texture (grass);
	return (img);
}

t_img	*load_bush_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*bush;

	bush = mlx_load_png("./Sprites/bush.png");
	if (!bush)
		error_message("Problem with loading png");
	img->bush = mlx_texture_to_image(mlx, bush);
	if (!img->bush)
		error_message("Problem with texture to image");
	mlx_delete_texture (bush);
	return (img);
}

t_img	*load_rupee_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*rupee;

	rupee = mlx_load_png("./Sprites/Rupee.png");
	if (!rupee)
		error_message("Problem with loading png");
	img->rupee = mlx_texture_to_image(mlx, rupee);
	if (!img->rupee)
		error_message("Problem with texture to image");
	mlx_delete_texture(rupee);
	return (img);
}

t_img	*load_exit_closed(mlx_t *mlx, t_img	*img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./Sprites/Exit_Closed.png");
	if (!exit)
		error_message("Problem with loading png");
	img->exit_closed = mlx_texture_to_image(mlx, exit);
	if (!img->exit_closed)
		error_message("Problem with texture to image");
	mlx_delete_texture(exit);
	return (img);
}

t_img	*load_exit_open(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./Sprites/Exit_Open.png");
	if (!exit)
		error_message("Problem with loading png");
	img->exit_open = mlx_texture_to_image(mlx, exit);
	if (!img->exit_open)
		error_message("Problem with texture to image");
	mlx_delete_texture(exit);
	return (img);
}
