/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:31:02 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/12 17:44:40 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>// open
#include <stdio.h>// printf

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s1 && s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		str[i + j] = s2[i];
		i++;
	}
	str[i + j] = '\0';
	return (str);
}

void	ft_main(char *file)
{
	int		i;
	int		fd;
	char	*str;

	file = ft_strjoin("../file/", file);
	i = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	printf("[BUFFER_SIZE = %d][fd = %i][%s]\n", BUFFER_SIZE, fd, file);
	while (str)
	{
		printf("[GNL%i]%s", ++i, str);
		free(str);
		str = get_next_line(fd);
	}
	printf("[GNL%i]%s[EOF]\n", ++i, str);
	free(file);
	close(fd);
	printf("----------------------------------------------------------------\n");
}

void	ft_main_2(void)
{
	int		i[] = {0, 0, 0};
	int		fd[3];
	char	*str[3];
	int		c;

	fd[0] = open("../file/notes", O_RDONLY);
	fd[1] = open("../file/notes2", O_RDONLY);
	fd[2] = open("../file/multiple_nlx5", O_RDONLY);
	c = -1;
	while (c++ < 2)
	{
		str[c] = get_next_line(fd[c]);
		printf("[BUFFER_SIZE = %d][fd[%i] = %i]\n", BUFFER_SIZE, c, fd[c]);
	}
	while (str[0] || str[1] || str[2])
	{
		c = -1;
		while (c++ < 2)
		{
			if (str[c])
			{
				printf("[GNL%i]%s", ++i[c], str[c]);
				free(str[c]);
				str[c] = get_next_line(fd[c]);
			}
		}
	}
	c = -1;
	while (c++ < 2)
		printf("[GNL%i]%s[EOF]\n", ++i[c], str[c]);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	printf("----------------------------------------------------------------\n");
}

void	ft_main_3(void)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = 0;
	str = get_next_line(fd);
	printf("[BUFFER_SIZE = %d][fd = %i]\n", BUFFER_SIZE, fd);
	printf("[GNL%i]%s", ++i, str);
	free(str);
	printf("----------------------------------------------------------------\n");
}

int	main(void)
{
	printf("----------------------------------------------------------------\n");
	ft_main("nl");
	ft_main("notes");
	ft_main("notes2");
	ft_main("empty");
	ft_main("multiple_nlx5");
	ft_main("short_line");
	ft_main("41_no_nl");
	ft_main("41_with_nl");
	ft_main("42_no_nl");
	ft_main("42_with_nl");
	ft_main("43_no_nl");
	ft_main("43_with_nl");
	ft_main_2();
	ft_main_3();
}
