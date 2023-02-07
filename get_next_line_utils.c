/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:00:34 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/07 18:11:31 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_strchr(const	char *s, int c)
{
	while (*s != '\0' && c != s)
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*get_line(int fd, char *line)
{
	char	*buf;
	size_t	i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = 1;
	while (!(ft_strchr(line, '\n')) && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0'; 
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_new_line(char *line)
{
	size_t	len_s;
	char	*s2;

	len_s = 0;
	while (line[len_s] != '\n')
		len_s++;
	s2 = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!s2)
		return (0);
	ft_memcpy(s2, line, (len_s + 1));
	return (s2);
}

char	*clean_new_line(char *line)
{
	size_t	i;
	
	i = 0;
	while (line[i] != '\n')
		i++;
	
	return (line + i + 1);
}

int	*get_next_line(int fd)
{
	static char *line;
	char		*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(line);
	string = get_new_line(line);
	line = clean_new_line(line);
	return (string);
}