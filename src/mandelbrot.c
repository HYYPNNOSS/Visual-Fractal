/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:45:26 by hel-hich          #+#    #+#             */
/*   Updated: 2022/07/13 21:10:14 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	check_iteration(int itr, float x, float y)
{
	int		i;
	t_cord	z;
	double	tmp;

	i = 0;
	z.x = 0;
	z.y = 0;
	while ((i < itr) && ((z.x * z.x + z.y * z.y) < 4))
	{
		tmp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + x;
		z.y = (2 * tmp * z.y) + y;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_var *fr)
{
	int			i;
	int			j;
	int			res;
	t_cord		cord;

	j = 0;
	while (j < 500)
	{
		i = 0;
		cord.y = fr->min.y + (j * (fr->max.y - fr->min.y)) / 500;
		while (i < 500)
		{
			cord.x = fr->min.x + (i * (fr->max.x - fr->min.x)) / 500;
			res = check_iteration(fr->itr, cord.x, cord.y);
			if (res != fr->itr)
				fr->mlx_addr[(j * 500) + i] = res * fr->color;
			else
				fr->mlx_addr[(j * 500) + i] = 0x000000;
			i++;
		}
		j++;
	}
}

int	ft_mandelbrot(t_var *var)
{
	var->max.x = 2;
	var->min.x = -2;
	var->max.y = 2;
	var->min.y = -2;
	var->itr = 250;
	draw_mandelbrot(var);
	return (0);
}
