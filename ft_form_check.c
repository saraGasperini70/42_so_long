/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:41:15 by sgasperi          #+#    #+#             */
/*   Updated: 2023/05/25 12:41:25 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Se non é rettangolare
void	ft_form_check(t_program *program)
{
	int	l;
	int	len;
	int	len2;

	l = 1;
	len = program->map_width;
	while (program->map[l])
	{
		len2 = ft_strlen(program->map[l]);
		if (len == len2)
			l++;
		else
			ft_free_alloc(program, 0);
	}
}
