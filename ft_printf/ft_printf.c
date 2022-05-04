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
		ft_putchar(s[i++]);
	return (i);
}

int	ft_printf_d(int d)
{
	return (0);
}

int	ft_printf_x(unsigned int x)
{
	return (0);
}

int	ft_conv(const char c, va_list list)
{
	int i;

	i = 0;
	if (c == 's')
		i = ft_printf_s((char *)va_arg(list, char *));
	if (c == 'd')
		i = ft_printf_d((int)va_arg(list, int));
	if (c == 'x')
		i = ft_printf_x((unsigned int)va_arg(list, unsigned int));
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	list;

	if (!s)
		return (0);
	va_start(list, s);
	i = 0;
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar(s[i++]);
			*s++;
		}
		else
		{
			*s++;
			i += ft_conv(*s, list);
			*s++;
		}
	}
	va_end(list);
    return (i);
}