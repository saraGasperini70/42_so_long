#include "so_long.h"

int ft_hooked_func(int key, t_program *program)
{
    if (key == 53)
        ft_exit(program);
  	else if (key == 13)
       ft_moveup(program);
   	else if (key == 1)
       ft_movedown(program);
   	else if (key == 0)
       ft_moveleft(program);
   	else if (key == 2)
       ft_moveright(program);
	return (0);
}

void ft_moveup(t_program *program)
{
	if (program->map[program->player_y - 1][program->player_x] == 'E' && program->collectibles == 0)
    {
        program->end_result = 1;
    }
    if (program->map[program->player_y - 1][program->player_x] == '0' 
                        || program->map[program->player_y - 1][program->player_x] == 'C')
    {
        if (program->map[program->player_y - 1][program->player_x] == 'C')
            program->collectibles--;
        program->map[program->player_y - 1][program->player_x] = 'P';
        ft_printf("%d\n", program->collectibles);
        program->map[program->player_y][program->player_x] = '0';
        program->player_y--;
    }
    program->moves++;
    ft_draw_map(program);
}
void ft_movedown(t_program *program)
{
    if (program->map[program->player_y + 1][program->player_x] == 'E' && program->collectibles == 0)
    {
        program->end_result = 1;
    }
    if (program->map[program->player_y + 1][program->player_x] == '0' 
                        || program->map[program->player_y + 1][program->player_x] == 'C')
    {
        if (program->map[program->player_y + 1][program->player_x] == 'C')
            program->collectibles--;
        program->map[program->player_y + 1][program->player_x] = 'P';
        ft_printf("%d\n", program->collectibles);
        program->map[program->player_y][program->player_x] = '0';
        program->player_y++;
    }
    program->moves++;
    ft_draw_map(program);
}

void ft_moveleft(t_program *program)
{
    if (program->map[program->player_y][program->player_x - 1] == 'E' && program->collectibles == 0)
    {
        program->end_result = 1;
    }
    if (program->map[program->player_y][program->player_x - 1] == '0' 
                        || program->map[program->player_y][program->player_x - 1] == 'C')
    {
        if (program->map[program->player_y][program->player_x - 1] == 'C')
            program->collectibles--;
        program->map[program->player_y][program->player_x - 1] = 'P';
        ft_printf("%d\n", program->collectibles);
        program->map[program->player_y][program->player_x] = '0';
        program->player_x--;
    }
    program->moves++;
    ft_draw_map(program);
}

void ft_moveright(t_program *program)
{
    if (program->map[program->player_y][program->player_x + 1] == 'E' && program->collectibles == 0)
    {
        ft_printf("%d\n", program->end_result);
        program->end_result = 1;
    }
    if (program->map[program->player_y][program->player_x + 1] == '0' 
                        || program->map[program->player_y][program->player_x + 1] == 'C')
    {
        if (program->map[program->player_y][program->player_x + 1] == 'C')
            program->collectibles--;
        program->map[program->player_y][program->player_x + 1] = 'P';
        ft_printf("%d\n", program->collectibles);
        program->map[program->player_y][program->player_x] = '0';
        program->player_x++;
    }
    program->moves++;
    ft_draw_map(program);
}

/*
void	ft_moveright(t_program *program)
{
//	mlx_clear_window(program->graphics.mlx_pointer, program->graphics.window);
//	program->graphics.counter++;
	if (program->map.map_array[program->player.x][program->player.y + 1] == '0' ||
		program->map.map_array[program->player.x][program->player.y + 1] == 'C')
	{
		program->map.map_array[program->player.x][program->player.y + 1] = 'P';
		program->map.map_array[program->player.x][program->player.y] = '0';
	}
	else if (program->map.map_array[program->player.x][program->player.y + 1] == 'E')
	{
		exit (0);
	}
    ft_print_array(program->map);
//	ft_scan_map(program);
}
*/