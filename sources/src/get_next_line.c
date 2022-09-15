/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/15 23:46:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// solo para open
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "get_next_line.h"

// Copia n bits del char y devuelve un puntero char con los bits copiados
// void *ft_put_line(const char *s, int n)
// {
// 	char *tmp;
// 	int		i;

// 	tmp = (char *)malloc(n + 1);
// 	if (!tmp)
// 		return (NULL);
// 	else
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			tmp[i] = s[i];
// 			i++;
// 		}
// 		tmp[i] = '\0';
// 	}
// 	return (tmp);
// }

void ft_tp_line_ex(t_print *tp, char **line, int len_tp, char *str)
{
	char *tmp_tp;

	if (str && !*line)
	{
		tmp_tp = (char *)ft_calloc_plus(len_tp, sizeof(tmp_tp));
		ft_memcpy(tmp_tp, tp->content, len_tp);
		*line = tmp_tp;
	}
	else if (str && *line)
	{
		tmp_tp = (char *)ft_calloc_plus(len_tp, sizeof(tmp_tp));
		ft_memcpy(tmp_tp, tp->content, len_tp);
		str = ft_strjoin(*line, "");
		free(*line);
		*line = ft_strjoin(str, tmp_tp);
		free(tmp_tp);
		free(str);
	}
	else
	{
		len_tp = ft_strlen(tp->content);
		str = ft_strjoin(*line, "");
		free(*line);
		*line = ft_strjoin(str, tp->content);
		free(str);
	}
	ft_cut_tp(tp, len_tp);
}

int	ft_tp_line(t_print *tp, char **line)
{
	char *str;
	int		len_tp;

	str = ft_strchr(tp->content, '\n');
	len_tp = str - tp->content + 1;
	if (str && !*line)
		ft_tp_line_ex(tp, &(*line), len_tp, str);
	else if (str && *line)
		ft_tp_line_ex(tp, &(*line), len_tp, str);
	else if (*tp->content && *line != NULL)
		ft_tp_line_ex(tp, &(*line), len_tp, str);
	else
	{
		len_tp = ft_strlen(tp->content);
		*line = ft_strjoin(tp->content, "");
		ft_cut_tp(tp, len_tp);
	}
	return (1);
}

int	ft_buffer(int fd, t_print *tp, char **line)
{
	if (!*tp->content)
		tp->size_buf = read(fd, tp->content, BUFFER_SIZE);
	if (tp->size_buf < 0)
		return (-1);
	if (*tp->content)
		ft_tp_line(tp, (&(*line)));
	if ((!tp->size_buf && !*line) || (!*tp->content && !tp->size_buf && *line))
		return (0);
	else if (!ft_strchr(*line, '\n'))
		ft_buffer(fd, tp, &(*line));
	return (1);
}

void *ft_calloc_plus(size_t count, size_t size)
{
	void *puntero;
	char *ch;
	size_t	i;

	puntero = malloc(count * size);
	if (!puntero)
		return (NULL);
	ch = puntero;
	i = 0;
	while (i < (count * size))
	{
		ch[i] = '\0';
		i++;
	}
	return (puntero);
}

char *get_next_line(int fd)
{
	static t_print *tp;
	char *line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tp)
		tp = (t_print *)ft_calloc_plus(sizeof(t_print), 1);
	if (!tp)
		return (NULL);
	line = (NULL);
	ft_buffer(fd, &(*tp), &line);
	if (line)
		return (line);
	else if ((!line && !((*tp)).size_buf) || (*tp).size_buf < 0)
	{
		if (tp)
			free(tp);
		tp = (NULL);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char *line;

// 	fd = open("../test/text-copy.txt", O_RDONLY);
// 	// fd = open("../test/text.txt", O_RDONLY);
// 	// fd = open("../test/giant_line.txt", O_RDONLY);
// 	// close(fd);

// 	// if (fd == -1)
// 	// 	return (-1);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 		{
// 			line = get_next_line(fd);
// 			break;
// 		}
// 		else if (line)
// 		{
// 			printf("%s", line);
// 			// printf("----------------\n");
// 			if (line)
// 				free(line);
// 		}
// 	}
// 	return (1);
// }
