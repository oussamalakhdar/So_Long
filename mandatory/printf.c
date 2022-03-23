/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:02:10 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/23 11:27:36 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*len = *len + 6;
		return ;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		(*len)++;
		i++;
	}
}

void	ft_putnbr(int nb, int *len)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', len);
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0', len);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putchar(nb % 10 + '0', len);
	}
}

int	ft_printf(char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format [i + 1] == '\0')
				break ;
			if (format [i + 1] == 's')
				ft_putstr(va_arg(arg, char *), &len);
			if (format[i + 1] == 'd')
				ft_putnbr(va_arg(arg, int), &len);
			i++;
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(arg);
	return (len);
}
