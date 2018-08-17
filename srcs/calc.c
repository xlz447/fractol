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

float	calc_cor(t_mlx *m, int cor, int md) // 0: x 1: y
{
	if (md == 0)
		return(((m->xy_mnmx[0] + m->xy_mnmx[1]) / 2 +
				(cor - (float)WIN_W / 2) * m->scale[0]));
		return(((m->xy_mnmx[2] + m->xy_mnmx[3]) / 2 +
				(cor - (float)WIN_H / 2) * m->scale[1]));	
}

void	shift(int k, t_mlx *m, float scale)
{
	float	shift;

	shift = WIN_W * scale * fabs(m->scale[0]);
	if (k >= 125)
		shift = WIN_H * scale * fabs(m->scale[1]);
	if (k == 126) // up
	{
		m->xy_mnmx[2] += shift;
		m->xy_mnmx[3] += shift;
	}
	else if (k == 125) // down
	{
		m->xy_mnmx[2] -= shift;
		m->xy_mnmx[3] -= shift;
	}
	else if (k == 123) // left
	{
		m->xy_mnmx[0] += shift;
		m->xy_mnmx[1] += shift;
	}
	else if (k == 124) // right
	{
		m->xy_mnmx[0] -= shift;
		m->xy_mnmx[1] -= shift;
	}
}