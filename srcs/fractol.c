# include "../includes/fractol.h"

int		col_code(int iter) // lol we need a col_code_2 to norm this
{
	//https://stackoverflow.com/questions/16500656/which-color-gradient-is-used-to-color-mandelbrot-in-wikipedia	
	if (iter % 16 == 0)
		return (65536 * 66 + 256 * 30 + 15);
	if (iter % 16 == 1)
		return (65536 * 25 + 256 * 7 + 26);
	if (iter % 16 == 2)
		return (65536 * 9 + 256 * 1 + 47);
	if (iter % 16 == 3)
		return (65536 * 4 + 256 * 4 + 73);
	if (iter % 16 == 4)
		return (65536 * 0 + 256 * 7 + 100);
	if (iter % 16 == 5)
		return (65536 * 12 + 256 * 44 + 138);
	if (iter % 16 == 6)
		return (65536 * 24 + 256 * 82 + 177);
	if (iter % 16 == 7)
		return (65536 * 57 + 256 * 125 + 209);
	if (iter % 16 == 8)
		return (65536 * 134 + 256 * 181 + 229);
	if (iter % 16 == 9)
		return (65536 * 211 + 256 * 236 + 248);
	if (iter % 16 == 10)
		return (65536 * 241 + 256 * 233 + 191);
	if (iter % 16 == 11)
		return (65536 * 248 + 256 * 201 + 95);
	if (iter % 16 == 12)
		return (65536 * 255 + 256 * 170 + 0);
	if (iter % 16 == 13)
		return (65536 * 204 + 256 * 128 + 0);
	if (iter % 16 == 14)
		return (65536 * 153 + 256 * 87 + 0);
	return (65536 * 106 + 256 * 52 + 3);
	
}

float	*calc_coor(t_mlx *m, int cor[2])
{
	float		to_ret[2];
	
	to_ret[0] = (m->x_mnmx[0] + m->x_mnmx[1]) / 2 + (cor[0] - (float)WIN_W / 2) * ((m->x_mnmx[1] - m->x_mnmx[0]) / WIN_W);  // new x
	to_ret[1] = (m->y_mnmx[0] + m->y_mnmx[1]) / 2 + (cor[1] - (float)WIN_H / 2) * ((m->y_mnmx[1] - m->y_mnmx[0]) / WIN_H); // new y
	return (to_ret);
}

void	draw_man(t_mlx *m)
{
	double	cur_rl;		// the current z (real part)
	double	cur_img;	// the current z (imaginary part)
	double	tmp;
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
				tmp = pow(cur_rl, 2) - pow(cur_img, 2) + calc_coor(m, cor)[0];
				cur_img = 2 * cur_rl * cur_img + calc_coor(m, cor)[1];
				cur_rl = tmp;
				i++;
			}		
			//if (pow(cur_rl, 2) + pow(cur_img, 2) <= m->max_dis)
				mlx_pixel_put(m->mlx, m->win, cor[0], cor[1], col_code(i));
			cor[0]++;
		}
		cor[1]++;
	}
}



void	draw(t_mlx *m)
{
	ft_putstr("Start Drawing\n");	
	if(m->set_mode == 0)
		draw_man(m);
	ft_putstr("Done Drawing\n");
}
