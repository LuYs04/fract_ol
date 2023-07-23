/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:09:17 by luatshem          #+#    #+#             */
/*   Updated: 2023/07/06 12:02:03 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_data *dt)
{
	int			x;
	int			y;
	t_complex	z;

	x = -1;
	while (++x < W)
	{
		y = -1;
		while (++y < H)
		{
			z.re = dt->min.re + (double)x * (dt->max.re - dt->min.re) / W;
			z.im = dt->min.im + (double)y * (dt->max.im - dt->min.im) / H;
			draw_julia(&z, dt, x, y);
		}
	}
}

void	draw_julia(t_complex *z, t_data *data, int a, int b)
{
	int		i;
	int		t;
	double	old_z_re;

	t = 0;
	i = 0;
	while (i++ < data->iter)
	{
		if (z->re * z->re + z->im * z->im > 4)
		{
			t = 1;
			break ;
		}
		old_z_re = z->re;
		z->re = z->re * z->re - z->im * z->im + data->k.re;
		z->im = 2 * old_z_re * z->im + data->k.im;
	}
	if (t)
		my_mlx_pixel_put(&data->image, a, b, i << 16 | i << 9 | i << 4);
}
