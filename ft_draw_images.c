/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:01:31 by sgasperi          #+#    #+#             */
/*   Updated: 2024/01/02 13:01:15 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_draw_images(t_program *program)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	program->image = ft_calloc(1, sizeof(t_image));
	program->image->wall = mlx_xpm_file_to_image(program->ptr,
			"./sprites/wall.xpm", &height, &width);
	program->image->escape = mlx_xpm_file_to_image(program->ptr,
			"./sprites/escape.xpm", &height, &width);
	program->image->collectible = mlx_xpm_file_to_image(program->ptr,
			"./sprites/collectible.xpm", &height, &width);
	program->image->floor = mlx_xpm_file_to_image(program->ptr,
			"./sprites/floor.xpm", &height, &width);
	program->image->player1 = mlx_xpm_file_to_image(program->ptr,
			"./sprites/player.xpm", &height, &width);
}
