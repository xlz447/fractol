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

float	calc_cor(t_mlx *m, int cor[2], int mode)
{
	if (mode == 0)
		return ((m->x_mnmx[0] + m->x_mnmx[1]) / 2 + (cor[0] - (float)WIN_W / 2)
				* ((m->x_mnmx[1] - m->x_mnmx[0]) / WIN_W));  // new x
	return ((m->y_mnmx[0] + m->y_mnmx[1]) / 2 + (cor[1] - (float)WIN_H / 2) *
			((m->y_mnmx[1] - m->y_mnmx[0]) / WIN_H)); // new y
}