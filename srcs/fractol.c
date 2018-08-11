# include "../includes/fractol.h"

# include <stdio.h>
float	*calc_coor(t_mlx *m, int cor[2])
{
	float		to_ret[2];
	
	to_ret[0] = (m->x_mnmx[0] + m->x_mnmx[1]) / 2 + (cor[0] - (float)WIN_W / 2) * ((m->x_mnmx[1] - m->x_mnmx[0]) / WIN_W);  // new x
	to_ret[1] = (m->y_mnmx[0] + m->y_mnmx[1]) / 2 + (cor[1] - (float)WIN_H / 2) * ((m->y_mnmx[1] - m->y_mnmx[0]) / WIN_H); // new y
	//printf("(%d, %d) -> (%f, %f)\n", cor[0], cor[1], to_ret[0], to_ret[1]);
	return (to_ret);
}

void	draw_man(t_mlx *m)
{
	float	cur_rl;		// the current z (real part)
	float	cur_img;	// the current z (imaginary part)
	int		i;			// the current iteration
	int		cor[2];		// the pixel coordinate (x, y)
	
	cor[1] = 0;
	while (cor[1] < WIN_H)
	{
		cor[0] = 0;
		while (cor[0] < WIN_W)
		{
			i = 0;
			cur_rl = 0;
			cur_img = 0;
			// loop stops when exceeed max distance or reach max iteration
			while (i <= m->max_iter && pow(cur_rl, 2) + pow(cur_img, 2) <= m->max_dis)
			{
				// real and imaginary part for z' = z ^ 2 + c, c from the pixel point
				cur_rl = pow(cur_rl, 2) - pow(cur_img, 2) + calc_coor(m, cor)[0];
				cur_img = 2 * cur_rl * cur_img + calc_coor(m, cor)[1];
				i++;
			}		
			if (pow(cur_rl, 2) + pow(cur_img, 2) <= m->max_dis)
				mlx_pixel_put(m->mlx, m->win, cor[0], cor[1], 0xffffff);
				//mlx_pixel_put(m->mlx, m->win, cor[0], cor[1], (i << 21) + (i << 10) + i * 8);
			cor[0]++;
		}
		cor[1]++;
	}
}



void	draw(t_mlx *m)
{
	if(m->set_mode == 0)
		draw_man(m);
}
