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


int	man_fifth_converge(t_mlx *m, int x, int y)
{
	double	i;
	double	r;
	double	tmp;
	int		iter;
	double	pxl_to_coor[2];

	iter = 0;
	i = 0;
	r = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		tmp = r * r * r * r * r - 10 * r * r * r * i * i + 5 * r * i * i * i * i + pxl_to_coor[0];
		i = 5 * r * r * r * r * i - 10 * r * r * i * i * i + i * i * i * i * i + pxl_to_coor[1];
		r = tmp;		
	}
	return (iter);
}


int		man_sixth_converge(t_mlx *m, int x, int y)
{
	double	i;
	double	r;
	double	tmp;
	int		iter;
	double	pxl_to_coor[2];

	iter = 0;
	i = 0;
	r = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		tmp = r * r * r - 3 * r * i * i + pxl_to_coor[0];
		i = 3 * r * r * i - i * i * i + pxl_to_coor[1];
		r = tmp;		
	}
	return (iter);
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
		return (man_fifth_converge(m, x, y));
	else if (m->set_mode == 7)
		return (man_sixth_converge(m, x, y));
	else
		return (0);
}
