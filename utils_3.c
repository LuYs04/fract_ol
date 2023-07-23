/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:32:01 by luatshem          #+#    #+#             */
/*   Updated: 2023/07/08 16:32:42 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	menu(t_data *dt)
{
	dt->menu = mlx_new_window(dt->mlx, 510, 150, "Menu");
	mlx_put_image_to_window(dt->mlx, dt->menu, dt->image.img, 0, 0);
	mlx_string_put(dt->mlx, dt->menu, 10, 10, 0xFFFFFF, \
			"Esc or q    -> Exit program\n");
	mlx_string_put(dt->mlx, dt->menu, 10, 30, 0xFFFFFF, \
			" - and +    -> Zoom in and out\n");
	mlx_string_put(dt->mlx, dt->menu, 10, 50, 0xFFFFFF, \
			"Mouse Wheel -> Zoom in and out\n");
	mlx_string_put(dt->mlx, dt->menu, 10, 70, 0xFFFFFF, \
			"Arrow Keys  -> Move fractal position\n");
	mlx_string_put(dt->mlx, dt->menu, 10, 90, 0xFFFFFF, \
			" i and k    -> Increase and decrease iterations\n");
	mlx_string_put(dt->mlx, dt->menu, 10, 110, 0xFFFFFF, \
			" l and .    -> Increase and decrease value of 'k'\n");
}

int	quit_with_x(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->menu);
	exit(0);
}
