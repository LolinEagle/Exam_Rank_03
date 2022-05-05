/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:32:07 by frrusso           #+#    #+#             */
/*   Updated: 2022/05/05 11:32:10 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf_s(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_printf_d(int d)
{
	int	i;

	i = 0;
	if (d == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		i = ft_printf_d(147483648);
		i++;
	}
	else if (d < 0)
	{
		ft_putchar('-');
		i = ft_printf_d(-d);
	}
	else if (d > 9)
	{
		i = ft_printf_d(d / 10);
		ft_printf_d(d % 10);
	}
	else
		ft_putchar(d + '0');
	return (i + 1);
}

int	ft_printf_x(long unsigned int hex)
{
	int		i;
	char	*hexa;

	hexa = "0123456789abcdef";
	if (hex > 15)
		i = ft_printf_x(hex / 16);
	ft_putchar(hexa[hex % 16]);
	return (i + 1);
}

int	ft_conv(char c, va_list list)
{
	int	i;

	i = 0;
	if (c == 's')
		i = ft_printf_s((char *)va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		i = ft_printf_d((int)va_arg(list, int));
	else if (c == 'x')
		i = ft_printf_x((long unsigned int)va_arg(list, long unsigned int));
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	list;

	i = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar(*s);
			i++;
		}
		else
		{
			s++;
			i += ft_conv(*s, list);
		}
		s++;
	}
	va_end(list);
	return (i);
}
