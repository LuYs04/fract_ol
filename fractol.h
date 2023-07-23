/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:08:46 by luatshem          #+#    #+#             */
/*   Updated: 2023/07/08 16:46:23 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W 1100
# define H 1100
# include <stdlib.h>
# include <mlx.h>
# include "printf/ft_printf.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;
typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;
typedef struct s_newton
{
	double	deriv_re;
	double	deriv_im;
	double	z_2_re;
	double	z_2_im;
	double	poly_re;
	double	poly_im;
	double	denominator;
}				t_newton;
typedef struct s_data
{
	int			t;
	int			iter;
	void		*mlx;
	void		*win;
	void		*menu;
	t_complex	c;
	t_complex	k;
	t_image		image;
	t_complex	min;
	t_complex	max;
	t_newton	n;
}				t_data;

void	error(void);
void	init(t_data *fr);
void	menu(t_data *dt);
void	julia(t_data *dt);
int		ft_strlen(char *s);
void	draw(t_data *data);
double	ft_atof(char *str);
void	newton(t_data *data);
void	check_ptr(void *ptr);
int		img_init(t_data *data);
void	mandelbrot(t_data *dt);
int		ft_atoi(const char *str);
int		quit_with_x(t_data *data);
void	zoom(int keycode, t_data *data);
void	move(int keycode, t_data *data);
void	change_k(int keycode, t_data *data);
int		key_press_hook(int keycode, t_data *data);
void	draw_newton(t_complex *z, t_data *dt, int a, int b);
void	draw_julia(t_complex *z, t_data *data, int a, int b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
int		mouse_press_hook(int button, int x, int y, t_data *data);
void	draw_mandelbrot(t_complex c, t_data *data, int a, int b);

#endif
