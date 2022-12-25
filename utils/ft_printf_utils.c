/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:54:12 by kmahdi            #+#    #+#             */
/*   Updated: 2022/12/20 22:26:32 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putnbr(int n)
{
	int				len;
	long long int	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += ft_putnbr (nb / 10);
		len += ft_putnbr (nb % 10);
	}
	else
		len += ft_putchar((nb + '0'));
	return (len);
}

int	ft_putstr(char *s)
{
	if (s)
	{
		write (1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (ft_putstr("(null)"));
}

int	ft_unsg(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 0 && n < 10)
	{
		ft_putchar ((n + 48));
		len++;
	}
	else
	{
		len += ft_unsg (n / 10);
		len += ft_unsg (n % 10);
	}
	return (len);
}
