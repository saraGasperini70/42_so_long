/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:38:38 by sgasperi          #+#    #+#             */
/*   Updated: 2024/01/23 12:30:50 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_extract_map(char *av, t_program *program)
{
	char	*new_mem;
	char	*tmp;
	char	*tmp2;
	int		fd;

	fd = open(av, O_RDONLY);
	new_mem = ft_calloc(1, 1);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		tmp2 = new_mem;
		new_mem = ft_strjoin(new_mem, tmp);
		free(tmp2);
		free(tmp);
		tmp = get_next_line(fd);
		program->map_height++;
	}
	free(tmp);
	program->map = ft_split(new_mem, '\n');
	free(new_mem);
	program->map_width = ft_strlen(program->map[0]);
}
