# include "../includes/fractol.h"

float	calc_cor(t_mlx *m, int cor, int md) // 0: x 1: y
{
	if (md == 0)
		return(((m->xy_mnmx[0] + m->xy_mnmx[1]) / 2 +
				(cor - (float)WIN_W / 2) * m->scale[0]));
		return(((m->xy_mnmx[2] + m->xy_mnmx[3]) / 2 -
				(cor - (float)WIN_H / 2) * m->scale[1]));	
}

void	shift(int k, t_mlx *m, float scale)
{
	float	shift;

	shift = WIN_W * scale * fabs(m->scale[0]);
	if (k >= 125)
		shift = WIN_H * scale * fabs(m->scale[1]);
	if (k == 126)
	{
		m->xy_mnmx[2] -= shift;
		m->xy_mnmx[3] -= shift;
	}
	else if (k == 125)
	{
		m->xy_mnmx[2] += shift;
		m->xy_mnmx[3] += shift;
	}
	else if (k == 123)
	{
		m->xy_mnmx[0] += shift;
		m->xy_mnmx[1] += shift;
	}
	else if (k == 124)
	{
		m->xy_mnmx[0] -= shift;
		m->xy_mnmx[1] -= shift;
	}
}