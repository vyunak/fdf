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

void	init_list(t_fdf *g_lst)
{
	g_lst->rad_x = 0;
	g_lst->rad_y = 0;
	g_lst->rad_z = 0;
	g_lst->skale = 3;
	g_lst->color = 0xffffff;
	g_lst->pos_pl = 0;
	g_lst->pos_pl2 = 0;
}

void	valide_map(t_fdf *g_lst, int x, int y)
{
	int temp;
	int i;

	temp = 0;
	i = 0;
	while (g_lst->map_t[y])
	{
		x = 0;
		while (g_lst->map_t[y][x].val)
		{
			if (g_lst->map_t[y][x].val != 1)
				exit(ft_printf("map error!\n"));
			x++;
		}
		if (temp != x)
		{
			temp = x;
			i++;
		}
		y++;
	}
	if (i > 1 || x == 0 || y == 0)
		exit(ft_printf("map error!\n"));
}
