/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_images.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/29 13:31:31 by arommers      ########   odam.nl         */
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

t_img	*initialize_img_struct(mlx_t *mlx)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_bush_texture(mlx, assets);
	return (assets);
}
