# include "../includes/fractol.h"

int		col_code(int iter)
{
	//https://stackoverflow.com/questions/16500656/which-color-gradient-is-used-to-color-mandelbrot-in-wikipedia
	int out[16];

	out[0] = 65536 * 66 + 256 * 30 + 15;
	out[1] = 65536 * 25 + 256 * 7 + 26;
	out[2] = 65536 * 9 + 256 * 1 + 47;
	out[3] = 65536 * 4 + 256 * 4 + 73;
	out[4] = 65536 * 0 + 256 * 7 + 100;
	out[5] = 65536 * 12 + 256 * 44 + 138;
	out[6] = 65536 * 24 + 256 * 82 + 177;
	out[7] = 65536 * 57 + 256 * 125 + 209;
	out[8] = 65536 * 134 + 256 * 181 + 229;
	out[9] = 65536 * 211 + 256 * 236 + 248;
	out[10] = 65536 * 241 + 256 * 233 + 191;
	out[11] = 65536 * 248 + 256 * 201 + 95;
	out[12] = 65536 * 255 + 256 * 170 + 0;
	out[13] = 65536 * 204 + 256 * 128 + 0;
	out[14] = 65536 * 153 + 256 * 87 + 0;
	out[15] = 65536 * 106 + 256 * 52 + 3;
	return (out[iter % 16]);
}

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