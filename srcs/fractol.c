/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 23:29:57 by xzhu              #+#    #+#             */
/*   Updated: 2018/08/31 23:30:01 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_converge(t_mlx *m, int x, int y)
{
	float	i;
	float	r;
	float	tmp;
	int		iter;

	iter = 0;
	i = calc_cor(m, x, 0);
	r = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		tmp = i * i - r * r + m->init_c[0];
		r = 2 * i * r + m->init_c[1];
		i = tmp;
	}
	return (iter);
}

int	ship_converge(t_mlx *m, int x, int y)
{
	float	i;
	float	r;
	float	tmp;
	int		iter;
	float	pxl_to_coor[2];

	iter = 0;
	i = 0;
	r = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		i = fabs(i);
		r = fabs(r);
		tmp = i * i - r * r + pxl_to_coor[0];
		r = 2 * i * r + pxl_to_coor[1];
		i = tmp;
	}
	return (iter);
}

int	lauren_converge(t_mlx *m, int x, int y)
{
	float	i;
	float	r;
	float	tmp;
	int		iter;
	float	pxl_to_coor[2];

	iter = 0;
	i = 0;
	r = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		tmp = fabs(i * i - r * r) + pxl_to_coor[0];
		r = 2 * i * r + pxl_to_coor[1];
		i = tmp;
	}
	return (iter);
}

int	man_converge(t_mlx *m, int x, int y)
{
	float	i;
	float	r;
	float	tmp;
	int		iter;
	float	pxl_to_coor[2];

	iter = 0;
	i = 0;
	r = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		tmp = i * i - r * r + pxl_to_coor[0];
		r = m->set_mode == 0 ? 2 * i * r + pxl_to_coor[1] :
								-2 * i * r + pxl_to_coor[1];
		i = tmp;
	}
	return (iter);
}

int	qualslash_converge(t_mlx *m, int x, int y)
{
	float	i;
	float	r;
	float	tmpx;
	float	tmpy;
	int		iter;

	iter = 0;
	i = calc_cor(m, x, 0);
	r = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		tmpx = (i * i * i * i) - (6 * i * i * r * r) + (r * r * r * r) +
				calc_cor(m, x, 0);
		tmpy = (4 * i * i * i * r) - (4 * i * r * r * r) + calc_cor(m, y, 1);
		i = tmpx;
		r = tmpy;
	}
	return (iter);
}
