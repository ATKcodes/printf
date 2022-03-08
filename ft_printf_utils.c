/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:37:24 by amaso             #+#    #+#             */
/*   Updated: 2022/02/28 14:37:26 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	c;

	c = 0;
	if (str)
	{
		while (str[c] != '\0')
		{
			write(1, &str[c], 1);
			c++;
		}
		return (c);
	}
	write (1, "(null)", 6);
	return (6);
}

void	ft_putnbr_u(unsigned int nb, int *c)
{
	char	l;

	l = 48 + nb % 10;
	if (nb > 9)
		ft_putnbr_u((nb / 10), c);
	write(1, &l, 1);
	(*c) = (*c) + 1;
}

void	ft_putnbr(int nb, int *c)
{
	char	l;

	if (nb == -2147483648)
	{
		ft_putnbr((nb / 10), c);
		write(1, "8", 1);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb, c);
	}
	else
	{
		if (nb > 9)
			ft_putnbr((nb / 10), c);
		l = 48 + nb % 10;
		write(1, &l, 1);
	}
	(*c) = (*c) + 1;
}

void	ft_putnbr_hex(unsigned int n, char *base, int *c)
{
	if (n / 16 != 0)
		ft_putnbr_hex(n / 16, base, c);
	write(1, &base[n % 16], 1);
	(*c) = (*c) + 1;
}

void	ft_puthex_p(unsigned long n, char *base, int *c)
{
	if (n / 16 != 0)
		ft_puthex_p(n / 16, base, c);
	write(1, &base[n % 16], 1);
	(*c) = (*c) + 1;
}
