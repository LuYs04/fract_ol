/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:09:54 by luatshem          #+#    #+#             */
/*   Updated: 2023/07/08 16:50:32 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		q;
	int		res;

	q = 0;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		q++;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (q == 1)
		res *= -1;
	return (res);
}

double	ft_atof(char *str)
{
	double	res1;
	double	res2;
	char	*s;
	int		len;

	res1 = ft_atoi(str);
	s = str;
	while (*s && *s != '.')
		s++;
	if (*s == '.')
		s++;
	res2 = ft_atoi(s);
	len = ft_strlen(s);
	while (len--)
		res2 /= 10;
	if (res1 > 0)
		return (res1 + res2);
	else
		return (res1 + (-1) * res2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	i = 0;
	while (s_1[i] && s_1[i] == s_2[i] && i < n)
		i++;
	if (i < n)
		return (s_1[i] - s_2[i]);
	else
		return (0);
}

void	error(void)
{
	ft_printf("%s\n", "Wrong input!");
	ft_printf("Type	'1' to see Mandelbrot fractal \n\
	'2' to see Julia fracatal \n\
	'3' to see Newton fracatal\n");
	exit(1);
}
