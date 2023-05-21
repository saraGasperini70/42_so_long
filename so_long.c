#include "so_long.h"

void	init_program(t_program *program)
{
	program->map_height = 0;
	program->map_width = 0;
	program->moves = 0;
	program->loop = 0;
	program->tStamp = 0;
	program->player_y = 0;
	program->player_x = 0;
	program->img_size = 64;
	program->collectibles = 0;
	program->end_result = -1;
}

int	main(int ac, char **av)
{
	t_program	program;
	
	init_program(&program);
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
	program.ptr = mlx_init();
	program.window = mlx_new_window(program.ptr, program.map_width * 64, program.map_height * 64, "so_long");
	ft_draw_images(&program);
	ft_draw_map(&program);
	mlx_key_hook(program.window, ft_hooked_func, &program);
	mlx_hook(program.window, 17, 0, ft_exit, &program);
	ft_printf("%d\n", program.collectibles);
	mlx_loop_hook(program.ptr, ft_timestamp_player, &program);
	mlx_loop(program.ptr);
}