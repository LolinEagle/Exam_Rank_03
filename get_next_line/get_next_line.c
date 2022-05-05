/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:55:14 by frrusso           #+#    #+#             */
/*   Updated: 2022/05/05 12:55:17 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>// printf

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
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
	if (s1)
		free(s1);
	return (str);
}

char	*ft_read(char *tmp, int fd)
{
	int		i;
	char	*buf;

	return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buf)
		return (NULL);
	i = 1;
	while (ft_strchr(tmp, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(tmp);
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin_free(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*ft_line(char *tmp)
{
	int		i;
	char	*res;

	i = 1;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	res = malloc(sizeof(char) * i);
	if (!res)
		return (NULL);
	res[i - 1] = '\0';
	i = -1;
	while (tmp[++i] && tmp[i] != '\n')
		res[i] = tmp[i];
	if (tmp[i] == '\n')
		res[i] = tmp[i];
	return (res);
}

char	*ft_save(char *tmp)
{
	int		i;
	int		c;
	char	*res;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!res)
		return (NULL);
	i++;
	c = 0;
	while (tmp[i])
		res[c++] = tmp[i++];
	res[c] = '\0';
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*res;

	if (fd < 0 || fd > 255 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = ft_read(tmp, fd);
	if (!tmp)
		return (NULL);
	res = ft_line(tmp);
	tmp = ft_save(tmp);
	return (res);
}
