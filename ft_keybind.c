/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keybind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:18:10 by sgasperi          #+#    #+#             */
/*   Updated: 2024/01/23 14:04:05 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_hooked_func(int key, t_program *program)
{
	if (key == 65307)
		ft_exit(program);
	else if (key == 119)
		ft_moveup(program);
	else if (key == 115)
		ft_movedown(program);
	else if (key == 97)
		ft_moveleft(program);
	else if (key == 100)
		ft_moveright(program);
	ft_printf("Moves: %d\n", program->moves);
	return (0);
}

void	ft_moveup(t_program *program)
{
	if (program->map[program->player_y - 1][program->player_x] == 'E'
		&& program->collectibles == 0)
	{
		program->end_result = 1;
	}
	if (program->map[program->player_y - 1][program->player_x] == '0'
		|| program->map[program->player_y - 1][program->player_x] == 'C')
	{
		if (program->map[program->player_y - 1][program->player_x] == 'C')
			program->collectibles--;
		program->map[program->player_y - 1][program->player_x] = 'P';
		program->map[program->player_y][program->player_x] = '0';
		program->player_y--;
	}
	program->moves++;
	ft_draw_map(program);
}

void	ft_movedown(t_program *program)
{
	if (program->map[program->player_y + 1][program->player_x] == 'E'
			&& program->collectibles == 0)
	{
		program->end_result = 1;
	}
	if (program->map[program->player_y + 1][program->player_x] == '0'
			|| program->map[program->player_y + 1][program->player_x] == 'C')
	{
		if (program->map[program->player_y + 1][program->player_x] == 'C')
			program->collectibles--;
		program->map[program->player_y + 1][program->player_x] = 'P';
		program->map[program->player_y][program->player_x] = '0';
		program->player_y++;
	}
	program->moves++;
	ft_draw_map(program);
}

void	ft_moveleft(t_program *program)
{
	if (program->map[program->player_y][program->player_x - 1] == 'E'
			&& program->collectibles == 0)
		program->end_result = 1;
	if (program->map[program->player_y][program->player_x - 1] == '0'
		|| program->map[program->player_y][program->player_x - 1] == 'C')
	{
		if (program->map[program->player_y][program->player_x - 1] == 'C')
			program->collectibles--;
		program->map[program->player_y][program->player_x - 1] = 'P';
		program->map[program->player_y][program->player_x] = '0';
		program->player_x--;
	}
	program->moves++;
	ft_draw_map(program);
}

void	ft_moveright(t_program *program)
{
	if (program->map[program->player_y][program->player_x + 1] == 'E'
			&& program->collectibles == 0)
	{
		program->end_result = 1;
	}
	if (program->map[program->player_y][program->player_x + 1] == '0'
			|| program->map[program->player_y][program->player_x + 1] == 'C')
	{
		if (program->map[program->player_y][program->player_x + 1] == 'C')
			program->collectibles--;
		program->map[program->player_y][program->player_x + 1] = 'P';
		program->map[program->player_y][program->player_x] = '0';
		program->player_x++;
	}
	program->moves++;
	ft_draw_map(program);
}
