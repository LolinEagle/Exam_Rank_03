/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:47:02 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/11 15:17:57 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// printf
#include <stddef.h>

#define PF printf
#define FT ft_printf

int ft_printf(const char *, ...);

void	ft_char(void)
{
	FT("- CHAR and %% -\n");
	PF("[%i]\n", PF("%c %c %c ", 33, 126, 255));
	PF("[%i]\n", FT("%c %c %c ", 33, 126, 255));
	PF("[%i]\n", PF("%c", '0'));
	PF("[%i]\n", FT("%c", '0'));
	PF("[%i]\n", PF(" %c ", '0'));
	PF("[%i]\n", FT(" %c ", '0'));
	PF("[%i]\n", PF(" %c", '0' - 256));
	PF("[%i]\n", FT(" %c", '0' - 256));
	PF("[%i]\n", PF("%c ", '0' + 256));
	PF("[%i]\n", FT("%c ", '0' + 256));
	PF("[%i]\n", PF(" %c %c %c ", '0', 0, '1'));
	PF("[%i]\n", FT(" %c %c %c ", '0', 0, '1'));
	PF("[%i]\n", PF(" %c %c %c ", ' ', ' ', ' '));
	PF("[%i]\n", FT(" %c %c %c ", ' ', ' ', ' '));
	PF("[%i]\n", PF(" %c %c %c ", '1', '2', '3'));
	PF("[%i]\n", FT(" %c %c %c ", '1', '2', '3'));
	PF("[%i]\n", PF(" %c %c %c ", '2', '1', 0));
	PF("[%i]\n", FT(" %c %c %c ", '2', '1', 0));
	PF("[%i]\n", PF(" %c %c %c ", 0, '1', '2'));
	PF("[%i]\n", FT(" %c %c %c ", 0, '1', '2'));
	PF("[%i]\n", PF("100~ %%"));
	PF("[%i]\n", FT("100~ %%"));
}

void	ft_string(void)
{
	char	*str;

	PF("\n- STRING -\n");
	str = "Bonsoir je fait 23 char";
	PF("[%i]\n", PF("%s", str));
	PF("[%i]\n", FT("%s", str));
	PF("[%i]\n", PF("%s", ""));
	PF("[%i]\n", FT("%s", ""));
	PF("[%i]\n", PF(" %s ", "-"));
	PF("[%i]\n", FT(" %s ", "-"));
	PF("[%i]\n", PF(" %s %s ", "", "-"));
	PF("[%i]\n", FT(" %s %s ", "", "-"));
	PF("[%i]\n", PF(" %s %s ", " - ", ""));
	PF("[%i]\n", FT(" %s %s ", " - ", ""));
	PF("[%i]\n", PF(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	PF("[%i]\n", FT(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	// PF("[%i]\n", PF(" NULL %s NULL ", NULL));
	// FT("[%i]\n", FT(" NULL %s NULL ", NULL));
}

void	ft_int(void)
{
	int				i;
	unsigned int	u;

	FT("\n- INT & DEC -\n");
	i = -2147483648;
	PF("[%i]\n", PF("%i", i));
	FT("[%i]\n", FT("%i", i));
	FT("\n- UNSIGNED -\n");
	u = 4294967295;
	PF("[%i]\n", PF("%u", u));
	FT("[%i]\n", FT("%u", u));
}

void	ft_ptr_hex(void)
{
	void	*v;
	char	*str;
	int		i;

	FT("\n- PTR -\n");
	v = str;
	PF("[%i]\n", PF("%p", v));
	FT("[%i]\n", FT("%p", v));
	FT("\n- HEX -\n");
	i = 448585456;
	PF("[%i]\n", PF("%x", i));
	FT("[%i]\n", FT("%x", i));
}

int	main(void)
{
	// ft_char();
	ft_string();
	// ft_int();
	// ft_ptr_hex();
}
