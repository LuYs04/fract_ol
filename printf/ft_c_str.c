/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:48:47 by luatshem          #+#    #+#             */
/*   Updated: 2023/02/21 17:49:09 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
