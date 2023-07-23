/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:49:22 by luatshem          #+#    #+#             */
/*   Updated: 2023/02/21 17:50:24 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		i;

	nb = n;
	count = 0;
	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		i = 1;
		nb *= -1;
	}
	if (nb >= 10)
		count = ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	count++;
	return (count + i);
}

int	ft_put_u_nbr(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb >= 10)
		count = ft_put_u_nbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	count++;
	return (count);
}

void	ft_check(char c, va_list arg, int *count)
{
	if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(arg, int));
	else if (c == 'c')
		*count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		*count += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
	{
		*count += ft_putstr("0x");
		*count += ft_putaddress(va_arg(arg, unsigned long long));
	}
	else if (c == 'x')
		*count += ft_putnbr_hex(va_arg(arg, unsigned int));
	else if (c == 'X')
		*count += ft_putnbr_hex_upper(va_arg(arg, unsigned int));
	else if (c == 'u')
		*count += ft_put_u_nbr(va_arg(arg, unsigned int));
	else
		*count += ft_putchar(c);
}
