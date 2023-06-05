#include "so_long.h"
void    ft_enemy_hor(t_program *program)
{
    if (program->map[program->enemy_hor.posy][program->enemy_hor.posx + 1] == '0')
        program->map[program->player_y][program->player_x + 1] = 'H'
		if (program->map[program->enemy_hor.posy - 1][program->enemy_hor.posx] == 'C' 
        || program->map[program->player_y][program->player_x + 1] = 'H'
)
        program->map[program->player_y][program->player_x + 1] = 'H'
        program->map[program->player_y][program->player_x] = '0'
}