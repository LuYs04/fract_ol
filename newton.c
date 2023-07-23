/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:09:17 by luatshem          #+#    #+#             */
/*   Updated: 2023/07/08 16:31:37 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	newton(t_data *dt)
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
			draw_newton(&z, dt, x, y);
		}
	}
}

void	draw_newton(t_complex *z, t_data *dt, int a, int b)
{
	int		i;

	i = 0;
	while (i++ < dt->iter)
	{
		dt->n.z_2_re = z->re * z->re * z->re - 3 * z->re * z->im * z->im;
		dt->n.z_2_im = 3 * z->re * z->re * z->im - z->im * z->im * z->im;
		dt->n.poly_re = dt->n.z_2_re - 1;
		dt->n.poly_im = dt->n.z_2_im;
		dt->n.deriv_re = 3 * z->re * z->re - 3 * z->im * z->im;
		dt->n.deriv_im = 6 * z->re * z->im;
		if (dt->n.poly_re * dt->n.poly_re + \
				dt->n.poly_im * dt->n.poly_im < 0.0001)
			break ;
		dt->n.denominator = dt->n.deriv_re * dt->n.deriv_re + \
							dt->n.deriv_im * dt->n.deriv_im;
		z->re -= (dt->n.poly_re * dt->n.deriv_re + \
				dt->n.poly_im * dt->n.deriv_im) / dt->n.denominator;
		z->im -= (dt->n.poly_im * dt->n.deriv_re - \
				dt->n.poly_re * dt->n.deriv_im) / dt->n.denominator;
	}
	my_mlx_pixel_put(&dt->image, a, b, i << 24 | i << 9 | i << 4);
}
