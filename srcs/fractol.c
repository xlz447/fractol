# include "../includes/fractol.h"

const int g_color[16] =
{
	65536 * 66 + 256 * 30 + 15,
	65536 * 25 + 256 * 7 + 26,
	65536 * 9 + 256 * 1 + 47,
	65536 * 4 + 256 * 4 + 73,
	65536 * 0 + 256 * 7 + 100,
	65536 * 12 + 256 * 44 + 138,
	65536 * 24 + 256 * 82 + 177,
	65536 * 57 + 256 * 125 + 209,
	65536 * 134 + 256 * 181 + 229,
	65536 * 211 + 256 * 236 + 248,
	65536 * 241 + 256 * 233 + 191,
	65536 * 248 + 256 * 201 + 95,
	65536 * 255 + 256 * 170 + 0,
	65536 * 204 + 256 * 128 + 0,
	65536 * 153 + 256 * 87 + 0,
	65536 * 106 + 256 * 52 + 3
};

int julia_converge(t_mlx *m, int x, int y)
{
	float	cur[3];
	float	pxl_to_coor[2];
	int		i;

	i = 0;
	cur[0] = calc_cor(m, x, 0);
	cur[1] = calc_cor(m, y, 1);
	while (i++ < m->mx_i && cur[0] * cur[0] + cur[1] * cur[1] <= m->mx_d)
	{
		cur[2] = cur[0] * cur[0] - cur[1] * cur[1] + m->init_c[0];
		cur[1] = 2 * cur[0] * cur[1] + m->init_c[1];
		cur[0] = cur[2];
	}
	return (i);
}

int ship_converge(t_mlx *m, int x, int y)
{
	float	cur[3];
	float	pxl_to_coor[2];
	int		i;

	i = 0;
	cur[0] = 0;
	cur[1] = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (i++ < m->mx_i && cur[0] * cur[0] + cur[1] * cur[1] <= m->mx_d)
	{
		cur[2] = cur[0] * cur[0] - cur[1] * cur[1] + pxl_to_coor[0];
		cur[1] = fabs(2 * cur[0] * cur[1]) + pxl_to_coor[1];
		cur[0] = fabs(cur[2]);
	}
	return (i);
}

int tricorn_converge(t_mlx *m, int x, int y)
{
	float	cur[3];
	float	pxl_to_coor[2];
	int		i;

	i = 0;
	cur[0] = 0;
	cur[1] = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (i++ < m->mx_i && cur[0] * cur[0] + cur[1] * cur[1] <= m->mx_d)
	{
		cur[2] = cur[0] * cur[0] - cur[1] * cur[1] + pxl_to_coor[0];
		cur[1] = 2 * cur[0] * cur[1] + pxl_to_coor[1];
		cur[0] = cur[2];
	}
	return (i);
}

int man_converge(t_mlx *m, int x, int y)
{
	float	cur[3];
	float	pxl_to_coor[2];
	int		i;

	i = 0;
	cur[0] = 0;
	cur[1] = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (i++ < m->mx_i && cur[0] * cur[0] + cur[1] * cur[1] <= m->mx_d)
	{
		cur[2] = cur[0] * cur[0] - cur[1] * cur[1] + pxl_to_coor[0];
		cur[1] = 2 * cur[0] * cur[1] + pxl_to_coor[1];
		cur[0] = cur[2];
	}
	return (i);
}

void draw(t_mlx *m)
{
	int		i;
	int		y;
	int		x;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			if (m->set_mode == 0)
				i = man_converge(m, x, y);
			else if (m->set_mode == 2)
				i = ship_converge(m, x, y);
			else if (m->set_mode == 1)
				i = julia_converge(m, x, y);
			((unsigned int *)m->ad)[(y * WIN_W + x)] = i <= m->mx_i ?
			g_color[i % 16] : 0;
		}
	}
	mlx_put_image_to_window (m->mlx, m->win, m->img, 0, 0);
}
