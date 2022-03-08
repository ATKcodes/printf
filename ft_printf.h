/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:35:29 by amaso             #+#    #+#             */
/*   Updated: 2022/02/28 14:35:32 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<stdarg.h>

int		ft_putstr(char *str);
void	ft_putnbr_u(unsigned int nb, int *c);
void	ft_putnbr(int nb, int *c);
void	ft_putnbr_hex(unsigned int n, char *base, int *i);
void	ft_puthex_p(unsigned long n, char *base, int *i);

int		ft_putchar(char c);
int		recognize_type(va_list *arg_ptr, char s);
int		ft_printf(const char *s, ...);

#endif
