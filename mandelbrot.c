/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:09:37 by luatshem          #+#    #+#             */
/*   Updated: 2023/07/06 11:58:23 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data *dt)
{
	int	x;
	int	y;

	x = -1;
	while (++x < W)
	{
		y = -1;
		while (++y < H)
		{
			dt->c.re = dt->min.re + (double)x * (dt->max.re - dt->min.re) / W;
			dt->c.im = dt->min.im + (double)y * (dt->max.im - dt->min.im) / H;
			draw_mandelbrot(dt->c, dt, x, y);
		}
	}
}

void	draw_mandelbrot(t_complex c, t_data *data, int a, int b)
{
	t_complex	z;
	double		old_z_re;
	int			k;
	int			i;

	k = 0;
	z.im = 0;
	z.re = 0;
	i = 0;
	while (i++ < data->iter)
	{
		if (z.re * z.re + z.im * z.im > 4)
		{
			k = 1;
			break ;
		}
		old_z_re = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * old_z_re * z.im + c.im;
	}
	if (k)
		my_mlx_pixel_put(&data->image, a, b, i << 16 | i << 8 | i << 4);
}
