/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:10:03 by luatshem          #+#    #+#             */
/*   Updated: 2023/07/08 16:37:21 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int keycode, t_data *data)
{
	if (keycode == 24)
	{
		data->min.re /= 1.5;
		data->min.im /= 1.5;
		data->max.re /= 1.5;
		data->max.im /= 1.5;
	}
	if (keycode == 27)
	{
		data->min.re *= 1.5;
		data->min.im *= 1.5;
		data->max.re *= 1.5;
		data->max.im *= 1.5;
	}
}

void	move(int keycode, t_data *data)
{
	if (keycode == 123 || keycode == 1)
	{
		data->max.re += 0.1;
		data->min.re += 0.1;
	}
	if (keycode == 124 || keycode == 2)
	{
		data->max.re -= 0.1;
		data->min.re -= 0.1;
	}
	if (keycode == 125 || keycode == 5)
	{
		data->max.im -= 0.1;
		data->min.im -= 0.1;
	}
	if (keycode == 126 || keycode == 4)
	{
		data->max.im += 0.1;
		data->min.im += 0.1;
	}
}

void	change_k(int keycode, t_data *data)
{
	if (keycode == 37)
	{
		if (data->k.re < 1.5)
		{
			data->k.re += 0.1;
			data->k.im -= 0.1;
		}
	}
	if (keycode == 47)
	{
		if (data->k.re > -1.5)
		{
			data->k.re -= 0.1;
			data->k.im += 0.1;
		}
	}
}

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->menu);
		exit(0);
	}
	if (keycode == 34)
		data->iter += 5;
	if (keycode == 40)
		data->iter -= 5;
	change_k(keycode, data);
	move(keycode, data);
	zoom(keycode, data);
	img_init(data);
	return (0);
}

int	mouse_press_hook(int button, int x, int y, t_data *data)
{
	t_complex	m;

	m.re = (double)x / (W / (data->max.re - data->min.re)) + data->min.re;
	m.im = (double)y / (H / (data->max.im - data->min.im)) + data->min.re;
	if (button == 5)
	{
		data->min.re = m.re + (data->min.re - m.re) * 0.5;
		data->min.im = m.im + (data->min.im - m.im) * 0.5;
		data->max.re = m.re + (data->max.re - m.re) * 0.5;
		data->max.im = m.im + (data->max.im - m.im) * 0.5;
	}
	if (button == 4)
	{
		data->min.re = m.re + (data->min.re - m.re) / 0.9;
		data->min.im = m.im + (data->min.im - m.im) / 0.9;
		data->max.re = m.re + (data->max.re - m.re) / 0.9;
		data->max.im = m.im + (data->max.im - m.im) / 0.9;
	}
	img_init(data);
	return (0);
}
