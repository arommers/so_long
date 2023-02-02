/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_images.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/02 14:45:52 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	*load_grass_texture(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./Sprites/grass.png");
	if (!grass)
		return (NULL);
	texture->grass = mlx_texture_to_image(mlx, grass);
	if (!texture->grass)
		return (NULL);
	mlx_delete_texture (grass);
	return (texture);
}

t_img	*load_bush_texture(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*bush;

	bush = mlx_load_png("./Sprites/bush.png");
	if (!bush)
		return (NULL);
	texture->bush = mlx_texture_to_image(mlx, bush);
	if (!texture->bush)
		return (NULL);
	mlx_delete_texture (bush);
	return (texture);
}

t_img	*load_rupee_texture(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*rupee;

	rupee = mlx_load_png("./Sprites/Rupee.png");
	if (!rupee)
		return (NULL);
	texture->rupee = mlx_texture_to_image(mlx, rupee);
	if (!texture->rupee)
		return (NULL);
	mlx_delete_texture(rupee);
	return (texture);
}

t_img	*load_exit_texture(mlx_t *mlx, t_img	*texture)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./Sprites/Exit_Closed.png");
	if (!exit)
		return (NULL);
	texture->exit = mlx_texture_to_image(mlx, exit);
	if (!texture->exit)
		return (NULL);
	mlx_delete_texture(exit);
	return (texture);
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
	assets = load_exit_texture(mlx, assets);
	return (assets);
}
