/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 23:30:36 by xzhu              #+#    #+#             */
/*   Updated: 2018/08/31 23:30:40 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_instructions(t_mlx *m)
{
	mlx_string_put(m->mlx, m->win, 5, 0, 0xFFFFFF, "Zoom: mouse wheel");
	mlx_string_put(m->mlx, m->win, 5, 20, 0xFFFFFF, "Recenter: mouse click");
	mlx_string_put(m->mlx, m->win, 5, 40, 0xFFFFFF,
		"Change interaction: keypad +/- ");
	mlx_string_put(m->mlx, m->win, 5, 60, 0xFFFFFF, "Change color set: c");
	mlx_string_put(m->mlx, m->win, 5, 80, 0xFFFFFF, "Shift: arrows");
	mlx_string_put(m->mlx, m->win, 5, 100, 0xFFFFFF,
		"Change Fractols: 1 2 3...");
	mlx_string_put(m->mlx, m->win, 5, 120, 0xFFFFFF,
		"Print Instructions: i");
}

void	setup(t_mlx *m)
{
	m->mx_i = 50;
	m->mx_d = 4;
	m->xy_mnmx[0] = -2;
	m->xy_mnmx[1] = 2;
	m->xy_mnmx[2] = -2;
	m->xy_mnmx[3] = 2;
	m->scale[0] = (m->xy_mnmx[1] - m->xy_mnmx[0]) / WIN_W;
	m->scale[1] = (m->xy_mnmx[3] - m->xy_mnmx[2]) / WIN_H;
	m->init_c[0] = 0;
	m->init_c[1] = 0;
	m->mouse[0] = 0;
	m->mouse[1] = 0;
	m->hold = 0;
	m->b_p_p = 8;
	m->s_l = 1 * WIN_W;
	m->end = 1;
	m->color_index = 0;
	change_color(m);
	m->ad = mlx_get_data_addr(m->img, &(m->b_p_p), &(m->s_l), &(m->end));
}

double	calc_cor(t_mlx *m, int cor, int md)
{
	if (md == 0)
		return (((m->xy_mnmx[0] + m->xy_mnmx[1]) / 2 +
				(cor - (double)WIN_W / 2) * m->scale[0]));
		return (((m->xy_mnmx[2] + m->xy_mnmx[3]) / 2 -
				(cor - (double)WIN_H / 2) * m->scale[1]));
}

void	shift(int k, t_mlx *m, double scale)
{
	double	shift;

	shift = WIN_W * scale * fabs(m->scale[0]);
	if (k >= 125)
		shift = WIN_H * scale * fabs(m->scale[1]);
	if (k == 126)
	{
		m->xy_mnmx[2] += shift;
		m->xy_mnmx[3] += shift;
	}
	else if (k == 125)
	{
		m->xy_mnmx[2] -= shift;
		m->xy_mnmx[3] -= shift;
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

void	draw(t_mlx *m)
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
			i = dispatch(m, x, y);
			((unsigned int *)m->ad)[((WIN_H - (y + 1)) * WIN_W + x)] =
			i <= m->mx_i ? m->color[i % 16] : 0;
		}
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
}
