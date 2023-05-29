/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:26:18 by sgasperi          #+#    #+#             */
/*   Updated: 2023/05/19 13:47:18 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_timestamp_player(t_program *program)
{
	if (program->loop < 5000)
	{
		program->loop++;
		return (0);
	}
	program->loop = 0;
	if (program->tStamp == 1)
	program->image->player1 = mlx_xpm_file_to_image(program->ptr,
				"./sprites/pl_1.xpm", &program->img_size, &program->img_size);
	else
	{
		program->image->player1 = mlx_xpm_file_to_image(program->ptr,
				"./sprites/pl_2.xpm", &program->img_size, &program->img_size);
		program->tStamp = 0;
	}
	ft_draw_map(program);
	program->tStamp++;
	return (0);
}

int	ft_timestamp_enemy_s(t_program *program)
{
	if (program->moves == program->enemy_short.move1)
	{
		program->image->enemy_s = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy1.xpm", &program->img_size, &program->img_size);
	}
	else if (program->moves == program->enemy_short.move2)
	{
		program->image->enemy_s = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy2.xpm", &program->img_size, &program->img_size);
	}
	if (program->moves == program->enemy_short.move3)
	{
		program->image->enemy_s = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy3.xpm", &program->img_size, &program->img_size);
	}
	ft_draw_map(program);
	return (0);
}

int	ft_timestamp_enemy_m(t_program *program)
{
	if (program->moves == program->enemy_medium.move1)
	{
		program->image->enemy_m = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy1.xpm", &program->img_size, &program->img_size);
	}
	else if (program->moves == program->enemy_medium.move2)
	{
		program->image->enemy_m = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy2.xpm", &program->img_size, &program->img_size);
	}
	if (program->moves == program->enemy_medium.move3)
	{
		program->image->enemy_m = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy3.xpm", &program->img_size, &program->img_size);
	}
	ft_draw_map(program);
	return (0);
}

int	ft_timestamp_enemy_l(t_program *program)
{
	if (program->moves == program->enemy_long.move1)
	{
		program->image->enemy_l = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy1.xpm", &program->img_size, &program->img_size);
	}
	else if (program->moves == program->enemy_long.move2)
	{
		program->image->enemy_l = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy2.xpm", &program->img_size, &program->img_size);
	}
	if (program->moves == program->enemy_long.move3)
	{
		program->image->enemy_l = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy3.xpm", &program->img_size, &program->img_size);
	}
	ft_draw_map(program);
	return (0);
}
