/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:18:27 by amaso             #+#    #+#             */
/*   Updated: 2022/02/28 14:18:31 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	recognize_type(va_list *arg_ptr, char s)
{
	int	c;

	c = 0;
	if (s == 'c')
		return (ft_putchar((char)va_arg((*arg_ptr), int)));
	else if (s == 's')
		return (ft_putstr(va_arg((*arg_ptr), char *)));
	else if (s == 'p')
	{	
		c += write(1, "0x", 2);
		ft_puthex_p(va_arg((*arg_ptr), unsigned long), "0123456789abcdef", &c);
	}
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg((*arg_ptr), int), &c);
	else if (s == 'u')
		ft_putnbr_u(va_arg((*arg_ptr), unsigned int), &c);
	else if (s == '%')
		c = write(1, "%", 1);
	else if (s == 'x')
		ft_putnbr_hex(va_arg((*arg_ptr), unsigned int), "0123456789abcdef", &c);
	else if (s == 'X')
		ft_putnbr_hex(va_arg((*arg_ptr), unsigned int), "0123456789ABCDEF", &c);
	return (c);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg_ptr;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	va_start(arg_ptr, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			counter = counter + recognize_type(&arg_ptr, s[i]);
		}
		else
		{
			counter++;
			write(1, &s[i], 1);
		}
		i++;
	}
	va_end(arg_ptr);
	return (counter);
}
