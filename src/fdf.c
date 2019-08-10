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

void	read_map_3(t_fdf *g_lst, int x, int y)
{
	int val;

	while (g_lst->map_4[x] != NULL)
	{
		val = 1;
		if (g_lst->map_4[x][0] == '-' || g_lst->map_4[x][0] == '+')
			val = (g_lst->map_4[x][1] &&
				ft_isdigit(g_lst->map_4[x][1]) == 1) ? 1 : -1;
		g_lst->map_t[y][x].z = ft_atoi(g_lst->map_4[x]);
		g_lst->map_t[y][x].x = x;
		g_lst->map_t[y][x].y = y;
		g_lst->map_t[y][x].val = val;
		x++;
	}
}

void	read_map_2(int end, t_fdf *g_lst, int fd, int y)
{
	char	*line;
	int		x;

	x = 0;
	while (++y < end)
	{
		get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
			exit(ft_printf("map error!\n"));
		g_lst->map_4 = ft_strsplit(line, ' ');
		x = 0;
		while (g_lst->map_4[x])
			x++;
		g_lst->map_t[y] = (t_map*)malloc(sizeof(t_map) * (x + 1));
		g_lst->map_t[y][x].x = 0;
		g_lst->map_t[y][x].y = 0;
		g_lst->map_t[y][x].z = 0;
		g_lst->map_t[y][x].val = 0;
		read_map_3(g_lst, 0, y);
		ft_free_arr(&g_lst->map_4);
		free(line);
	}
	g_lst->size_y = y;
	g_lst->size_x = x;
}

void	read_map(int fd, const char *av, t_fdf *g_lst)
{
	int		i;
	int		x;
	char	*line;

	i = 0;
	x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	fd = open(av, O_RDONLY);
	g_lst->map_t = (t_map**)malloc(sizeof(t_map*) * (i + 1));
	g_lst->map_t[i] = NULL;
	read_map_2(i, g_lst, fd, -1);
	valide_map(g_lst, 0, 0);
	init_list(g_lst);
}

void	create_window(int fd, const char *av)
{
	t_fdf	g_lst;

	read_map(fd, av, &g_lst);
	g_lst.mlx_ptr = mlx_init();
	g_lst.win_ptr = mlx_new_window(g_lst.mlx_ptr, 900, 900, (char*)av);
	mlx_hook(g_lst.win_ptr, 2, 1L << 17, key_press, &g_lst);
	mlx_hook(g_lst.win_ptr, 17, 1L << 17, ft_exit, (void*)0);
	clear_and_paint(&g_lst);
	mlx_loop(g_lst.mlx_ptr);
}

int		main(int argc, char const *argv[])
{
	int fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_printf("usage: ./fdf <filename>\n");
		else if (read(fd, 0, 0) == -1)
			ft_printf("No data found.\n");
		else
			create_window(fd, argv[1]);
	}
	else
		ft_printf("error\n");
	return (0);
}
