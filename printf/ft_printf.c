/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:24:45 by luatshem          #+#    #+#             */
/*   Updated: 2023/02/24 19:23:03 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			ft_check(s[++i], arg, &count);
		}
		else if (s[i] == '%' && !s[i + 1])
			break ;
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
