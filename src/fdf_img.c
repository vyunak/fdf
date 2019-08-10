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

void	print_line(t_fdf *g_lst, double **coord)
{
	t_tline lst;
	t_tline lst1;

	lst.mlx_ptr = g_lst->mlx_ptr;
	lst1.mlx_ptr = g_lst->mlx_ptr;
	lst.win_ptr = g_lst->win_ptr;
	lst1.win_ptr = g_lst->win_ptr;
	lst.x1 = (coord[0][0] * g_lst->skale + g_lst->pos);
	lst.x2 = (coord[1][0] * g_lst->skale + g_lst->pos);
	lst.y1 = (coord[0][1] * g_lst->skale + g_lst->pos2);
	lst.y2 = (coord[1][1] * g_lst->skale + g_lst->pos2);
	lst1.x1 = (coord[0][0] * g_lst->skale + g_lst->pos);
	lst1.x2 = (coord[2][0] * g_lst->skale + g_lst->pos);
	lst1.y1 = (coord[0][1] * g_lst->skale + g_lst->pos2);
	lst1.y2 = (coord[2][1] * g_lst->skale + g_lst->pos2);
	lst.color = g_lst->color;
	lst1.color = g_lst->color;
	line(lst);
	line(lst1);
}

void	calc_print(t_fdf *g_lst, int x, int y)
{
	double		**coord;
	double		ns[2][3];

	coord = (double**)malloc(sizeof(double*) * 3);
	coord[3] = NULL;
	coord[0] = calc_this_place(g_lst->map_t[y][x].x - g_lst->size_x / 2,
		g_lst->map_t[y][x].y - g_lst->size_y / 2, g_lst->map_t[y][x].z, g_lst);
	ns[0][0] = (g_lst->map_t[y][x + 1].x) ?
		g_lst->map_t[y][x + 1].x : g_lst->map_t[y][x].x;
	ns[0][1] = (g_lst->map_t[y][x + 1].x) ?
		g_lst->map_t[y][x + 1].y : g_lst->map_t[y][x].y;
	ns[0][2] = (g_lst->map_t[y][x + 1].x) ?
		g_lst->map_t[y][x + 1].z : g_lst->map_t[y][x].z;
	ns[1][0] = (g_lst->map_t[y + 1]) ?
		g_lst->map_t[y + 1][x].x : g_lst->map_t[y][x].x;
	ns[1][1] = (g_lst->map_t[y + 1]) ?
		g_lst->map_t[y + 1][x].y : g_lst->map_t[y][x].y;
	ns[1][2] = (g_lst->map_t[y + 1]) ?
		g_lst->map_t[y + 1][x].z : g_lst->map_t[y][x].z;
	coord[1] = calc_this_place(ns[0][0] - g_lst->size_x / 2,
		ns[0][1] - g_lst->size_y / 2, ns[0][2], g_lst);
	coord[2] = calc_this_place(ns[1][0] - g_lst->size_x / 2,
		ns[1][1] - g_lst->size_y / 2, ns[1][2], g_lst);
	print_line(g_lst, coord);
	ft_free_arr_f(&coord);
}

void	put_info(t_fdf *g_lst, char *coord[4])
{
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		10, 10, 0xffffff, "+/- ZOOM:");
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		105, 10, 0xffffff, coord[3]);
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		10, 30, 0xffffff, "W/S RADIUS X:");
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		145, 30, 0xffffff, coord[0]);
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		10, 50, 0xffffff, "A/D RADIUS Y:");
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		145, 50, 0xffffff, coord[1]);
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		10, 70, 0xffffff, "Q/E RADIUS Z:");
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		145, 70, 0xffffff, coord[2]);
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		10, 150, 0xffffff, "ARROWS -> displacement.");
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		10, 110, 0xffffff, "R/T projections.");
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		10, 130, 0xffffff, "C -> RANDOM COLOR.");
	mlx_string_put(g_lst->mlx_ptr, g_lst->win_ptr,
		10, 90, 0xffffff, "SPACE -> RESET.");
}

void	put_win_info(t_fdf *g_lst)
{
	char	*coord[4];

	coord[0] = ft_itoa(g_lst->rad_x / 0.01745329251);
	coord[1] = ft_itoa(g_lst->rad_y / 0.01745329251);
	coord[2] = ft_itoa(g_lst->rad_z / 0.01745329251);
	coord[3] = ft_itoa(g_lst->skale);
	put_info(g_lst, coord);
	free(coord[0]);
	free(coord[1]);
	free(coord[2]);
	free(coord[3]);
}

void	clear_and_paint(t_fdf *g_lst)
{
	int		y;
	int		x;

	mlx_clear_window(g_lst->mlx_ptr, g_lst->win_ptr);
	control_rad(g_lst);
	y = 0;
	g_lst->pos = (900 / 2) + g_lst->pos_pl;
	g_lst->pos2 = (900 / 2) + g_lst->pos_pl2;
	while (y < g_lst->size_y)
	{
		x = 0;
		while (x < g_lst->size_x)
		{
			calc_print(g_lst, x, y);
			x++;
		}
		y++;
	}
	put_win_info(g_lst);
}
