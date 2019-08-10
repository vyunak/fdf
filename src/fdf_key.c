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

void		key_press_v3(int keycode, t_fdf *lst)
{
	if (keycode == 78)
	{
		if (lst->skale - 0.2 > 1)
			lst->skale -= 0.3;
	}
	else if (keycode == 8)
		lst->color += 0xb42121 / 2;
	else if (keycode == 15)
	{
		lst->rad_x = -0.785399;
		lst->rad_y = 0.610866;
		lst->rad_z = -0.523599;
		lst->pos_pl = 0;
		lst->pos_pl2 = 0;
		lst->color = 0xffffff;
	}
	else if (keycode == 17)
	{
		lst->rad_x = 1.5708;
		lst->rad_y = 0;
		lst->rad_z = 1.5708;
		lst->pos_pl = 0;
		lst->pos_pl2 = 0;
		lst->color = 0xffffff;
	}
}

void		key_press_v2(int keycode, t_fdf *lst)
{
	if (keycode == 126)
	{
		if (lst->pos_pl2 - 5 > (double)-450 - lst->size_y / 2)
			lst->pos_pl2 -= 5;
	}
	else if (keycode == 1)
		lst->rad_x += 0.0872666;
	else if (keycode == 2)
		lst->rad_y += 0.0872666;
	else if (keycode == 12)
		lst->rad_z -= 0.0872666;
	else if (keycode == 13)
		lst->rad_x -= 0.0872666;
	else if (keycode == 69)
		(lst->skale < 25) ? lst->skale += 0.3 : 0;
	else if (keycode == 49)
		init_list(lst);
	else if (keycode == 14)
		lst->rad_z += 0.0872666;
	else if (keycode == 0)
		lst->rad_y -= 0.0872666;
	else
		key_press_v3(keycode, lst);
}

int			key_press(int keycode, void *param)
{
	t_fdf *lst;

	lst = (t_fdf*)param;
	if (keycode == 53)
		exit(1);
	else if (keycode == 124)
	{
		if (lst->pos_pl + 5 < (double)450 + lst->size_x / 2)
			lst->pos_pl += 5;
	}
	else if (keycode == 125)
	{
		if (lst->pos_pl2 + 5 < (double)450 + lst->size_y / 2)
			lst->pos_pl2 += 5;
	}
	else if (keycode == 123)
	{
		if (lst->pos_pl - 5 > (double)-450 - lst->size_x / 2)
			lst->pos_pl -= 5;
	}
	else
		key_press_v2(keycode, lst);
	clear_and_paint(lst);
	return (1);
}

int			ft_exit(void *p)
{
	p = NULL;
	exit(1);
}
