/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:11:50 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/16 15:13:09 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_free_arr(char ***str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = *str;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (NULL);
}

void	*ft_free_arr_f(double ***str)
{
	double	**tmp;
	int		i;

	i = 0;
	tmp = *str;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (NULL);
}
