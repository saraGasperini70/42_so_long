/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:47:52 by sgasperi          #+#    #+#             */
/*   Updated: 2023/05/25 12:47:40 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Se la mappa non é un .ber
void	ft_check_ber(char *av)
{
	int	l;

	l = ft_strlen(av);
	if (!(av[l - 1] == 'r' && av[l - 2] == 'e' && av[l - 3] == 'b'
			&& av[l - 4] == '.'))
	{
		ft_printf("Errore: la mappa deve essere in formato .ber\n");
		exit(0);
	}
}

//Se errore, libera la memoria e restituisce un messaggio in base all'errore 
void	ft_free_alloc(t_program *program, int z)
{
	int	i;

	i = 0;
	while (program->map[i])
	{
		free(program->map[i]);
		i++;
	}
	free(program->map[i]);
	free(program->map);
	if (z == 2)
		ft_printf("Errore: La mappa non possiede tutti gli elementi necessari");
	if (z == 1)
		ft_printf("Errore: La mappa deve essere chiusa.\n");
	if (z == 0)
		ft_printf("Errore: La mappa non é rettangolare.\n");
	exit(0);
}

// Se la mappa non ha tutti gli elementi giusti
void	ft_check_player(t_program *program)
{
	int	i;
	int	j;
	int	pla;

	i = 0;
	pla = 0;
	while (program->map[i])
	{
		j = 0;
		while (program->map[i][j])
		{
			if (program->map[i][j] == 'P')
			{
				pla++;
				program->player_y = i;
				program->player_x = j;
			}
			j++;
		}
	i++;
	}
	if (pla == 0 || ex == 0)
		ft_free_alloc(program, 2);
}

void	ft_check_player(t_program *program)
{
	int	i;
	int	j;
	int	pla;
	int	ex;

	i = 0;
	pla = 0;
	ex = 0;
	while (program->map[i])
	{
		j = 0;
		while (program->map[i][j])
		{
			if (program->map[i][j] == 'E')
				ex++;
			if (program->map[i][j] == 'C')
				program->collectibles++;
			j++;
		}
		i++;
	}
	if (pla == 0 || ex == 0)
		ft_free_alloc(program, 2);
}

void	ft_check_map(t_program *program)
{
	ft_form_check(program);
	ft_walls_check(program);
	ft_check_elements(program);
}
