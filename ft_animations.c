#include "so_long.h"

int    ft_timestamp_player(t_program *program)
{
	// write (1, &program->tStamp, 1);
    if (program->loop < 5000)
    {
        program->loop++;
        return (0);
    }
    program->loop = 0;
    if (program->tStamp == 1)
    {
        program->image->player1 = mlx_xpm_file_to_image(program->ptr,
                                    "./sprites/player.xpm", &program->img_size, &program->img_size);
    }
    else
    {
        program->image->player1 = mlx_xpm_file_to_image(program->ptr,
                                    "./sprites/player2.xpm", &program->img_size, &program->img_size);
        program->tStamp = 0;
    }
    ft_draw_map(program);
    program->tStamp++;
    return (0);
}