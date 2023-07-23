/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:27:56 by luatshem          #+#    #+#             */
/*   Updated: 2023/02/24 19:23:30 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putstr(char *s);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_put_u_nbr(unsigned int nb);
int		ft_putnbr_hex(unsigned int nb);
int		ft_putnbr_hex_upper(unsigned int nb);
int		ft_putaddress(unsigned long long p);
void	ft_check(char c, va_list arg, int *count);
int		ft_printf(const char *s, ...);

#endif
