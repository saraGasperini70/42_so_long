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

#include "includes/so_long.h"

int	ft_timestamp_player(t_program *program)
{
	if (program->loop < 5000)
	{
		program->loop++;
		return (0);
	}
	program->loop = 0;
	if (program->tstamp == 1)
	program->image->player1 = mlx_xpm_file_to_image(program->ptr,
				"./sprites/pl_1.xpm", &program->img_size, &program->img_size);
	else
	{
		program->image->player1 = mlx_xpm_file_to_image(program->ptr,
				"./sprites/pl_2.xpm", &program->img_size, &program->img_size);
		program->tstamp = 0;
	}
	ft_draw_map(program);
	program->tstamp++;
	return (0);
}

int	ft_timestamp_enemy_hor(t_program *program)
{
	if (program->moves == 0)
	{
		program->image->enemy_hor = mlx_xpm_file_to_image(program->ptr,
				"./sprites/egg.xpm", &program->img_size, &program->img_size);
	}
	else
	{
		ft_animate_enemy_h(program);
	}
	ft_draw_map(program);
	return (0);
}

int	ft_timestamp_enemy_vert(t_program *program)
{
	if (program->moves == 0)
	{
		program->image->enemy_vert = mlx_xpm_file_to_image(program->ptr,
				"./sprites/egg.xpm", &program->img_size, &program->img_size);
	}
	else
	{
		ft_animate_enemy_v(program);
	}
	ft_draw_map(program);
	return (0);
}

int	ft_timestamp_enemy_foll(t_program *program)
{
	if (program->moves == 0)
	{
		program->image->enemy_foll = mlx_xpm_file_to_image(program->ptr,
				"./sprites/egg.xpm", &program->img_size, &program->img_size);
	}
	else
	{
		ft_animate_enemy_f(program);
	}
	ft_draw_map(program);
	return (0);
}
