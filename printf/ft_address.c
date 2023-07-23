/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:37:11 by luatshem          #+#    #+#             */
/*   Updated: 2023/02/21 17:52:20 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nb)
{
	unsigned long long		n;
	int						count;

	n = (unsigned long long)nb;
	count = 0;
	if (n >= 16)
		count = ft_putnbr_hex(n / 16);
	count++;
	ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putnbr_hex_upper(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb >= 16)
		count = ft_putnbr_hex_upper(nb / 16);
	count++;
	ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (count);
}

int	ft_putaddress(unsigned long long p)
{
	int		count;

	count = 0;
	if (p >= 16)
		count = ft_putaddress(p / 16);
	ft_putchar("0123456789abcdef"[p % 16]);
	count++;
	return (count);
}
