/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:58:47 by sgasperi          #+#    #+#             */
/*   Updated: 2023/05/25 12:59:04 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

//Se non é chiusa/circondata da muri
void	ft_walls_check(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->map_height)
	{
		if (program->map[i][0] == '1'
				&& program->map[i][program->map_width - 1] == '1')
			i++;
		else
			ft_free_alloc(program, 1);
	}
	i = 0;
	while (i < program->map_width)
	{
		if (program->map[0][i] == '1'
				&& program->map[program->map_height - 1][i] == '1')
			i++;
		else
			ft_free_alloc(program, 1);
	}
}
