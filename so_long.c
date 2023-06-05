/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:50:19 by sgasperi          #+#    #+#             */
/*   Updated: 2023/05/25 12:34:14 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_program(t_program *program)
{
	program->map_height = 0;
	program->map_width = 0;
	program->moves = 0;
	program->loop = 0;
	program->tstamp = 0;
	program->player_y = 0;
	program->player_x = 0;
	program->img_size = 64;
	program->collectibles = 0;
	program->end_result = -1;
}

void	ft_pre_checks(t_program program)
{
	if (ac == 2)
	{
		ft_check_ber(av[1]);
		ft_extract_map(av[1], &program);
		ft_check_map(&program);
	}
	else if (ac < 2)
	{
		ft_printf("Error: Nessuna mappa inserita");
		exit (0);
	}
	else
	{		
		ft_printf("Error: Troppi argomenti inseriti");
		exit (0);
	}
}

int	main(int ac, char **av)
{
	t_program	program;

	init_program(&program);
	ft_pre_checks(program);
	program.ptr = mlx_init();
	program.window = mlx_new_window(program.ptr,
			program.map_width * 64, program.map_height * 64, "so_long");
	ft_draw_images(&program);
	ft_draw_map(&program);
	mlx_key_hook(program.window, ft_hooked_func, &program);
	mlx_hook(program.window, 17, 0, ft_exit, &program);
	mlx_loop_hook(program.ptr, ft_timestamp_player, &program);
	ft_timestamp_enemy_l(&program);
	ft_timestamp_enemy_m(&program);
	ft_timestamp_enemy_s(&program);
	mlx_loop(program.ptr);
	ft_exit(&program);
}
