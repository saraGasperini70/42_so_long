/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:07:00 by sgasperi          #+#    #+#             */
/*   Updated: 2024/01/02 13:04:20 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"


void	ft_image_to_win(t_program *program, int i, int j)
{
	if (program->map[i][j] == 'C')
	{
		mlx_put_image_to_window(program->ptr, program->window,
			program->image->floor, j * 64, i * 64);
		mlx_put_image_to_window(program->ptr, program->window,
			program->image->collectible, j * 64, i * 64);
	}
	if (program->map[i][j] == 'E')
	{
		if (program->collectibles == 0)
			mlx_put_image_to_window(program->ptr, program->window,
				program->image->escape, j * 64, i * 64);
		else
			mlx_put_image_to_window(program->ptr, program->window,
				program->image->floor, j * 64, i * 64);
	}
}

void	ft_put_image_to_win_plus(t_program *program, int i, int j)
{
	if (program->map[i][j] == '1')
		mlx_put_image_to_window(program->ptr, program->window,
			program->image->wall, j * 64, i * 64);
	if (program->map[i][j] == '0')
		mlx_put_image_to_window(program->ptr, program->window,
			program->image->floor, j * 64, i * 64);
	if (program->map[i][j] == 'P')
	{
		mlx_put_image_to_window(program->ptr, program->window,
			program->image->floor, j * 64, i * 64);
		mlx_put_image_to_window(program->ptr, program->window,
			program->image->player1, j * 64, i * 64);
	}
}

void	ft_draw_map(t_program *program)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = ft_itoa(program->moves);
	if (program->end_result != -1)
		return ;
	while (program->map[i])
	{
		j = 0;
		while (program->map[i][j])
		{
			ft_image_to_win(program, i, j);
			ft_put_image_to_win_plus(program, i, j);
			j++;
		}
		i++;
	}
	mlx_string_put(program->ptr, program->window, program->map_width / 2,
		program->map_height / 2, 0x000000, str);
	ft_endgame(program);
	free(str);
}
