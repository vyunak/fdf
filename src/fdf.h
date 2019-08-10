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

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"

typedef struct	s_dop
{
	double		dis;
	double		dx;
	double		x;
	double		dy;
	double		y;
	double		lengthx;
	double		lengthy;
	double		length;
}				t_dop;

typedef struct	s_line
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	int				color;
}				t_tline;

typedef struct	s_map
{
	double			y;
	double			x;
	double			z;
	int				val;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map_4;
	double		skale;
	double		pos;
	double		pos2;
	double		pos_pl;
	double		pos_pl2;
	double		rad_z;
	double		rad_y;
	double		rad_x;
	int			animation;
	int			color;
	int			size_x;
	int			size_y;
	t_map		**map_t;

}				t_fdf;

void			linex(t_tline lst, t_dop vinston);
void			liney(t_tline lst, t_dop vinston);
void			line(t_tline lst);
double			*calc_this_place(double x, double y, double z, t_fdf *g_lst);
void			control_rad(t_fdf *g_lst);
void			print_line(t_fdf *g_lst, double **coord);
void			calc_print(t_fdf *g_lst, int x, int y);
void			put_info(t_fdf *g_lst, char *coord[4]);
void			put_win_info(t_fdf *g_lst);
void			clear_and_paint(t_fdf *g_lst);
void			init_list(t_fdf *g_lst);
void			valide_map(t_fdf *g_lst, int x, int y);
void			key_press_v3(int keycode, t_fdf *lst);
void			key_press_v2(int keycode, t_fdf *lst);
int				key_press(int keycode, void *param);
int				ft_exit(void *p);
void			read_map_3(t_fdf *g_lst, int x, int y);
void			read_map_2(int end, t_fdf *g_lst, int fd, int y);
void			read_map(int fd, const char *av, t_fdf *g_lst);
void			create_window(int fd, const char *av);
int				main(int argc, char const *argv[]);

#endif
