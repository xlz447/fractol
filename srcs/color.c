/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 23:38:28 by xzhu              #+#    #+#             */
/*   Updated: 2018/08/31 23:38:30 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	colorset0(t_mlx *m)
{
	const int color[16] = {
		0xffff7d,
		0xffee7d,
		0xffdf7e,
		0xffcf7e,
		0xffbf7e,
		0xffaf7e,
		0xff9f7e,
		0xff8f7f,
		0xfe7e7f,
		0xee6f7f,
		0xde5e7f,
		0xce4f7f,
		0xbe3f7f,
		0xae2f7f,
		0x9d1f7f,
		0x8d0e7f
	};

	m->color = color;
}

static void	colorset1(t_mlx *m)
{
	const int color[16] = {
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

	m->color = color;
}

static void	colorset2(t_mlx *m)
{
	const int color[16] = {
		0xffffff,
		0xdfffff,
		0xbfffff,
		0xa0ffff,
		0x80ffff,
		0x60dfff,
		0x3fbfff,
		0x1f9fff,
		0x7efe,
		0x5edf,
		0x3fbf,
		0x1fa0,
		0x80,
		0x60,
		0x3f,
		0x1f
	};

	m->color = color;
}

static void	colorset3(t_mlx *m)
{
	const int color[16] = {
		0xFF0005,
		0xFD5800,
		0xFCB600,
		0xE3FB00,
		0x85FA00,
		0x27F900,
		0x00F836,
		0x00F791,
		0x01F5EC,
		0x01A2F4,
		0x0147F3,
		0x1501F2,
		0x6E01F1,
		0xC701F0,
		0xEF01BF,
		0xED0166
	};

	m->color = color;
}

void		change_color(t_mlx *m, int k)
{
	m->color_index = k == 43 ? (m->color_index) - 1 : (m->color_index) + 1;
	if (m->color_index == -1)
		m->color_index = 3;
	else if (m->color_index == 4)
		m->color_index = 0;
	if (m->color_index == 0)
		colorset0(m);
	else if (m->color_index == 1)
		colorset1(m);
	else if (m->color_index == 2)
		colorset2(m);
	else if (m->color_index == 3)
		colorset3(m);
}
