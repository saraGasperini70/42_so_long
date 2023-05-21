#include "so_long.h"

int	ft_exit(t_program *program)
{
	int	i;

	i = 0;
	mlx_destroy_image(program->ptr, program->image->wall);
	mlx_destroy_image(program->ptr, program->image->player1);
	// mlx_destroy_image(program->ptr, program->image->enemy1);
	mlx_destroy_image(program->ptr, program->image->escape);
	mlx_destroy_image(program->ptr, program->image->collectible);
	mlx_destroy_image(program->ptr, program->image->floor);
	mlx_destroy_window(program->ptr, program->window);
	while (program->map[i])
	{
		free(program->map[i]);
		i++;
	}
	free(program->map[i]);
	free(program->map);
	exit (0);
}
