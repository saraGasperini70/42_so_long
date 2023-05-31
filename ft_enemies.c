#include "so_long.h"
void    ft_enemy_h(t_program *program)
{
    if (program->loop < 5000)
	{
		program->loop++;
		return (0);
	}
	program->loop = 0;
	if (program->tStamp == 1)
	program->image->player1 = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy.xpm", &program->img_size, &program->img_size);
	else
	{
		program->image->player1 = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy2.xpm", &program->img_size, &program->img_size);
		program->tStamp = 0;
	}
	ft_draw_map(program);
	program->tStamp++;
	return (0);
}

void    ft_animate_enemy_h(t_program *program)
{
    if (program->loop < 5000)
	{
		program->loop++;
		return (0);
	}
	program->loop = 0;
	if (program->tStamp == 1)
	program->image->enemy_hor = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy.xpm", &program->img_size, &program->img_size);
	else
	{
		program->image->enemy_hor = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy.xpm", &program->img_size, &program->img_size);
		program->tStamp = 0;
	}
	ft_draw_map(program);
	program->tStamp++;
	return (0);
}

void    ft_animate_enemy_v(t_program *program)
{
    if (program->loop < 5000)
	{
		program->loop++;
		return (0);
	}
	program->loop = 0;
	if (program->tStamp == 1)
	program->image->enemy_ver = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy1.xpm", &program->img_size, &program->img_size);
	else
	{
		program->image->enemy_ver = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy2.xpm", &program->img_size, &program->img_size);
		program->tStamp = 0;
	}
	ft_draw_map(program);
	program->tStamp++;
	return (0);
}

void    ft_animate_enemy_f(t_program *program)
{
    if (program->loop < 5000)
	{
		program->loop++;
		return (0);
	}
	program->loop = 0;
	if (program->tStamp == 1)
	program->image->enemy_fol = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy1.xpm", &program->img_size, &program->img_size);
	else
	{
		program->image->enemy_fol = mlx_xpm_file_to_image(program->ptr,
				"./sprites/enemy2.xpm", &program->img_size, &program->img_size);
		program->tStamp = 0;
	}
	ft_draw_map(program);
	program->tStamp++;
	return (0);
}