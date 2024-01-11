#include "includes/so_long.h"
t_bool    ft_move_hor(t_program *program)
{
    if (program->enemy_hor.dir == 0)
        return (ft_enemy_left(program));
    else
        return (ft_enemy_right(program))

}

t_bool    ft_move_hor(t_program *program)
{
    if (program->enemy_hor.dir == 0)
        return (ft_enemy_up(program));
    else
        return (ft_enemy_down(program))
}

void    ft_enemy_left(t_program *program)
{
    if (program->map[program->enemy_hor.posy][program->enemy_hor.posx - 1] == '0')
        program->enemy_hor.posx--
    if (program->map[program->enemy_hor.posy][program->enemy_hor.posx - 1] == 'P')
    {
        program->map[program->enemy_hor.posy][program->enemy_hor.posx - 1] = 'M';
        program->map[program->enemy_hor.posy][program->enemy_hor.posx] = "0";
        program->end_result = 0;
        ft_endgame(program);
    }
}