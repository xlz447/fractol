/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morefractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:32:49 by xzhu              #+#    #+#             */
/*   Updated: 2018/09/01 19:32:50 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		test1_converge(t_mlx *m, int x, int y)
{
	double	i;
	double	r;
	double	tmpi;
	double	tmpr;
	int		iter;

	iter = 0;
	i = calc_cor(m, x, 0);
	r = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i + r <= m->mx_d)
	{
		i = 2 * fabs(i + r) + m->init_c[1];
		r = tmpi - tmpr - m->init_c[0];
		tmpr = r * r;
		tmpi = i * i;
	}
	return (iter);
}

int		test2_converge(t_mlx *m, int x, int y)
{
	double	i;
	double	r;
	double	tmpi;
	double	tmpr;
	int		iter;

	iter = 0;
	i = calc_cor(m, x, 0);
	r = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i + r <= m->mx_d)
	{
		i = 2 * fabs(i + r) + m->init_c[1];
		r = tmpi - tmpr - m->init_c[0];
		tmpr = r * r;
		tmpi = i * i;
	}
	return (iter);
}

int		dispatch(t_mlx *m, int x, int y)
{
	if (m->set_mode == 0 || m->set_mode == 3)
		return (man_converge(m, x, y));
	else if (m->set_mode == 1)
		return (julia_converge(m, x, y));
	else if (m->set_mode == 2)
		return (ship_converge(m, x, y));
	else if (m->set_mode == 4)
		return (lauren_converge(m, x, y));
	else if (m->set_mode == 5)
		return (qualslash_converge(m, x, y));
	else if (m->set_mode == 6)
		return (test1_converge(m, x, y));
	else if (m->set_mode == 7)
		return (test2_converge(m, x, y));
	else
		return (0);
}
