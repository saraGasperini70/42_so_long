/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:17:19 by sgasperi          #+#    #+#             */
/*   Updated: 2024/01/26 12:12:46 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_exit(t_program *program)
{
	int	i;

	i = 0;
	mlx_destroy_image(program->ptr, program->image->wall);
	mlx_destroy_image(program->ptr, program->image->player1);
	mlx_destroy_image(program->ptr, program->image->escape);
	mlx_destroy_image(program->ptr, program->image->collectible);
	mlx_destroy_image(program->ptr, program->image->floor);
	mlx_destroy_window(program->ptr, program->window);
	free(program->image);
	while (program->map[i])
	{
		free(program->map[i]);
		i++;
	}
	free(program->map[i]);
	free(program->map);
	exit (0);
}
