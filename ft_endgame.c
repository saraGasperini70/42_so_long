#include "so_long.h"

void	ft_endgame(t_program *program)
{
	// mlx_clear_window(program->ptr, program->window);
	if (program->end_result == 1)
	{
		mlx_string_put(program->ptr, program->window, program->map_width / 2, program->map_height / 2, 0x000000, "You Won!");
	}		
	else if (program->end_result == 0)
	{
		mlx_string_put(program->ptr, program->window, program->map_width / 2, program->map_height / 2, 0x000000, "GAME OVER");
	}
	// ft_exit(program);
}
		