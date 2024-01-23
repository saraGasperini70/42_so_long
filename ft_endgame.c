/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:15:41 by sgasperi          #+#    #+#             */
/*   Updated: 2024/01/23 13:49:21 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_endgame(t_program *program)
{
	if (program->end_result == 1)
	{
		mlx_string_put(program->ptr, program->window, program->map_width / 2,
			program->map_height / 2, 0x000000, "You Won!");
		ft_exit(program);
	}
	else if (program->end_result == 0)
	{
		mlx_string_put(program->ptr, program->window, program->map_width / 2,
			program->map_height / 2, 0x000000, "GAME OVER");
		ft_exit(program);
	}
}
