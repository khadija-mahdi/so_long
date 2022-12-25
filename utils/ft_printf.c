/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:56:27 by kmahdi            #+#    #+#             */
/*   Updated: 2022/12/16 20:36:43 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_hex(unsigned long n)
{
	char	*p;
	int		nb;

	nb = 0;
	p = "0123456789abcdef";
	if (n >= 0 && n < 16)
	{
		ft_putchar(p[n]);
		nb++;
	}
	else if (n >= 16)
	{
		nb += ft_hex (n / 16);
		nb += ft_hex (n % 16);
	}
	return (nb);
}

int	ft_hex_up(unsigned int n)
{
	char	*p;
	int		nbr;

	nbr = 0;
	p = "0123456789ABCDEF";
	if (n < 16)
	{
		nbr += ft_putchar(p[n]);
	}
	else if (n >= 16)
	{
		nbr += ft_hex_up (n / 16);
		nbr += ft_hex_up (n % 16);
	}
	return (nbr);
}

int	ft_print_check(char a, va_list s)
{
	int	i;

	i = 0;
	if (a == '%')
		i += ft_putchar('%');
	else if (a == 'c')
		i += ft_putchar(va_arg(s, int));
	else if (a == 'd' || a == 'i')
		i += ft_putnbr(va_arg(s, int));
	else if (a == 's')
		i += ft_putstr(va_arg(s, char *));
	else if (a == 'p')
	{
		i += ft_putstr("0x");
		i += ft_hex(va_arg(s, unsigned long));
	}
	else if (a == 'u')
		i += ft_unsg(va_arg(s, unsigned int));
	else if (a == 'X')
		i += ft_hex_up(va_arg(s, unsigned int));
	else if (a == 'x')
		i += ft_hex(va_arg(s, unsigned int));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		f;
	va_list	list;

	i = 0;
	f = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			f += ft_print_check(format[i], list);
		}
		else
		{
			ft_putchar(format[i]);
			f++;
		}
		i++;
	}
	va_end(list);
	return (f);
}
