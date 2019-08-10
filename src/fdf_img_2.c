/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:26:43 by vyunak            #+#    #+#             */
/*   Updated: 2019/05/23 11:26:44 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			linex(t_tline lst, t_dop vinston)
{
	vinston.dis = -vinston.lengthx;
	while (vinston.length--)
	{
		if (vinston.x > 0 && vinston.x < 900 &&
			vinston.y > 0 && vinston.y < 900)
			mlx_pixel_put(lst.mlx_ptr, lst.win_ptr,
				vinston.x, vinston.y, lst.color);
		vinston.x += vinston.dx;
		vinston.dis += 2 * vinston.lengthy;
		if (vinston.dis > 0)
		{
			vinston.dis -= 2 * vinston.lengthx;
			vinston.y += vinston.dy;
		}
	}
}

void			liney(t_tline lst, t_dop vinston)
{
	vinston.dis = -vinston.lengthy;
	while (vinston.length--)
	{
		if (vinston.x > 0 && vinston.x < 900 &&
			vinston.y > 0 && vinston.y < 900)
			mlx_pixel_put(lst.mlx_ptr, lst.win_ptr,
				vinston.x, vinston.y, lst.color);
		vinston.y += vinston.dy;
		vinston.dis += 2 * vinston.lengthx;
		if (vinston.dis > 0)
		{
			vinston.dis -= 2 * vinston.lengthy;
			vinston.x += vinston.dx;
		}
	}
}

void			line(t_tline lst)
{
	t_dop vinston;

	vinston.x = lst.x1;
	vinston.y = lst.y1;
	vinston.dx = (lst.x2 - vinston.x >= 0 ? 1 : -1);
	vinston.dy = (lst.y2 - vinston.y >= 0 ? 1 : -1);
	vinston.lengthx = (int)(lst.x2 - vinston.x);
	(vinston.lengthx < 0) ? vinston.lengthx *= -1 : 0;
	vinston.lengthy = (int)(lst.y2 - vinston.y);
	(vinston.lengthy < 0) ? vinston.lengthy *= -1 : 0;
	if (vinston.lengthy < vinston.lengthx)
		vinston.length = vinston.lengthx + 1;
	else
		vinston.length = vinston.lengthy + 1;
	if (vinston.lengthy <= vinston.lengthx)
		linex(lst, vinston);
	else
		liney(lst, vinston);
}

double			*calc_this_place(double x, double y, double z, t_fdf *g_lst)
{
	double	*coord;
	double	temp;

	coord = (double*)malloc(sizeof(double) * 3);
	coord[0] = x;
	coord[1] = y * cos(g_lst->rad_x) + z * sin(g_lst->rad_x);
	coord[2] = -y * sin(g_lst->rad_x) + z * cos(g_lst->rad_x);
	temp = coord[0];
	coord[0] = coord[0] * cos(g_lst->rad_y) + coord[2] * sin(g_lst->rad_y);
	coord[2] = -temp * sin(g_lst->rad_y) + coord[2] * cos(g_lst->rad_y);
	temp = coord[0];
	coord[0] = coord[0] * cos(g_lst->rad_z) - coord[1] * sin(g_lst->rad_z);
	coord[1] = temp * sin(g_lst->rad_z) + coord[1] * cos(g_lst->rad_z);
	return (coord);
}

void			control_rad(t_fdf *g_lst)
{
	if (g_lst->rad_y <= -6.283188 || g_lst->rad_y >= 6.283188)
		g_lst->rad_y = 0;
	if (g_lst->rad_x <= -6.283188 || g_lst->rad_x >= 6.283188)
		g_lst->rad_x = 0;
	if (g_lst->rad_z <= -6.283188 || g_lst->rad_z >= 6.283188)
		g_lst->rad_z = 0;
}
