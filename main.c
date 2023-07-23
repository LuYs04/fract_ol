/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:09:08 by luatshem          #+#    #+#             */
/*   Updated: 2023/07/06 11:53:21 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_data *fr)
{
	fr->t = 1;
	fr->mlx = 0;
	fr->win = 0;
	fr->menu = 0;
	fr->iter = 70;
	fr->image.img = 0;
	fr->c.re = 0;
	fr->c.im = 0;
	fr->k.re = -0.79;
	fr->k.im = 0.15;
	fr->max.re = 1.7;
	fr->min.re = -1.7;
	fr->max.im = 1.5;
	fr->min.im = fr->max.im - ((fr->max.re - fr->min.re) * (H / W));
}

int	img_init(t_data *data)
{
	if (data->mlx && data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	data->image.img = mlx_new_image(data->mlx, W, H);
	data->image.addr = mlx_get_data_addr(data->image.img, \
			&data->image.bits_per_pixel, \
			&data->image.line_length, &data->image.endian);
	if (data->t == 1)
		mandelbrot(data);
	else if (data->t == 2)
		julia(data);
	else if (data->t == 3)
		newton(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (0);
}

void	draw(t_data *data)
{
	data->mlx = mlx_init();
	if (data->t == 1)
		data->win = mlx_new_window(data->mlx, W, H, "Mandelbrot");
	else if (data->t == 2)
		data->win = mlx_new_window(data->mlx, W, H, "Julia");
	else if (data->t == 3)
		data->win = mlx_new_window(data->mlx, W, H, "Newton");
	img_init(data);
}

void	mlx_draw_fractal(int argc, char **argv, t_data *data)
{
	if (!ft_strncmp(argv[1], "1", ft_strlen(argv[1])))
	{
		data->max.re = 1.5;
		data->min.re = -2;
		data->max.im = 1.5;
	}
	else if (!ft_strncmp(argv[1], "2", ft_strlen(argv[1])))
	{
		if (argc == 4)
		{
			data->k.re = ft_atof(argv[2]);
			data->k.im = ft_atof(argv[3]);
		}
		data->t = 2;
	}
	else if (!ft_strncmp(argv[1], "3", ft_strlen(argv[1])))
		data->t = 3;
	else
		error();
	draw(data);
}

int	main(int argc, char **argv)
{
	t_data	d;
	t_data	*data;

	init(&d);
	data = &d;
	if (argc < 2)
	{
		ft_printf("Type	'1' to see Mandelbrot fractal \n\
	'2' to see Julia fracatal \n\
	'3' to see Newton fracatal\n");
		exit (0);
	}
	mlx_draw_fractal(argc, argv, data);
	mlx_hook(data->win, 2, 1L << 2, key_press_hook, data);
	mlx_hook(data->win, 17, 1L << 17, quit_with_x, data);
	mlx_mouse_hook(data->win, mouse_press_hook, data);
	menu(data);
	mlx_loop(data->mlx);
	return (0);
}
