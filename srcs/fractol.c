# include "../includes/fractol.h"

int		*calc_coor(int x, int y)
{
	int	to_ret[2]; 
	
	to_ret[0] = 0;  // new x (real)
	to_ret[1] = 0;  // new y (imagery)
	return (to_ret);
}

void	draw_man(t_mlx *m)
{
	float	cur_rl;
	float	cur_img;
	int		cur_iter;
	
	cur_iter = 0;
	cur_rl = calc_coor(0,0)[0];
	cur_img = calc_coor(0,0)[1];
	while (cur_iter <= m->max_iter && pow(cur_rl, 2) + pow(cur_img, 2) < m->max_dis)
	{
		mlx_pixel_put(m->mlx, m->win, (int)cur_rl, (int)cur_img, 0xffffff);
		cur_rl++;
		cur_img++;
	}
}



void	draw(t_mlx *m)
{
	if(m->set_mode == 0)
		draw_man(m);
}
