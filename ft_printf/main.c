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

#define PF printf
#define FT ft_printf

int	ft_printf(const char *s, ...);

void	ft_string(void)
{
	char	*str;

	FT("\n- STRING -\n");
	str = "Bonsoir je fait 23 char";
	PF("[%i]\n", PF("%s", str));
	FT("[%i]\n", FT("%s", str));
	PF("[%i]\n", PF("%s", ""));
	FT("[%i]\n", FT("%s", ""));
	PF("[%i]\n", PF(" %s ", "-"));
	FT("[%i]\n", FT(" %s ", "-"));
	PF("[%i]\n", PF(" %s %s ", "", "-"));
	FT("[%i]\n", FT(" %s %s ", "", "-"));
	PF("[%i]\n", PF(" %s %s ", " - ", ""));
	FT("[%i]\n", FT(" %s %s ", " - ", ""));
	PF("[%i]\n", PF(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	FT("[%i]\n", FT(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	PF("[%i]\n", PF(" NULL %s NULL ", NULL));
	FT("[%i]\n", FT(" NULL %s NULL ", NULL));
}

void	ft_int(void)
{
	int	i;

	FT("\n- INT & DEC -\n");
	i = -2147483648;
	PF("[%i]\n", PF("%i", i));
	FT("[%i]\n", FT("%i", i));
	i = -2147483647;
	PF("[%i]\n", PF("%i", i));
	FT("[%i]\n", FT("%i", i));
	i = 2147483647;
	PF("[%i]\n", PF("%i", i));
	FT("[%i]\n", FT("%i", i));
	i = 0;
	PF("[%i]\n", PF("%i", i));
	FT("[%i]\n", FT("%i", i));
}

void	ft_ptr_hex(void)
{
	void	*v;
	char	*str;
	int		i;

	FT("\n- HEX -\n");
	i = 448585456;
	PF("[%i]\n", PF("%x", i));
	FT("[%i]\n", FT("%x", i));
}

int	main(void)
{
	ft_string();
	ft_int();
	ft_ptr_hex();
	FT("\n");
}
