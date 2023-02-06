/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:00:34 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/06 17:52:18 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Questo ciclo "while" continua a eseguirsi finché o La funzione 
	"ft_strchr" restituisce un valore diverso da NULL, indicando che il 
	carattere di nuova riga ('\n') è stato trovato nella stringa "line" 
	o Il valore restituito da "read" è minore o uguale a zero, indicando 
	che non ci sono più dati da leggere dal file descrittore 
	o che si è verificato un errore. */
}
char	*get_line(int fd, char *line)
{
	char	*buf;
	size_t	b;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	b = 1;
	while (!(ft_strchr(line, '\n')) && b > 0)
	{
		b = read( fd, *buf, BUFFER_SIZE);
		if (b == -1)
		{
			free(buf);
			return (NULL);
		}
		free(buf);
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_new_line(char *line)
{
	
}

char	*clean_new_line(char *line)
{
	
}

get_next_line(int fd)
{
	
}