/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/13 20:55:37 by nmota-bu         ###   ########.fr       */
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
void *ft_put_line(const char *s, int n)
{
	char *tmp;
	int		i;

	tmp = (char *)malloc(n);
	if (!tmp)
		return (NULL);
	else
	{
		i = 0;
		while (i < n)
		{
			tmp[i] = s[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

void ft_tp_line_ex(t_print *tp, char **line, int len_tp, char *str)
{
	char *tmp_tp;

	if (str && !*line)
		*line = ft_put_line(tp->content, len_tp);
	else if (str && *line)
	{
		tmp_tp = ft_put_line(tp->content, len_tp);
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
		*line = ft_put_line(tp->content, len_tp);
		ft_cut_tp(tp, len_tp);
	}
	return (1);
}

int	ft_buffer(int fd, t_print *tp, char **line)
{
	if (!*tp->content)
		tp->size_buf = read(fd, tp->content, BUFFER_SIZE);
	if (*tp->content)
		ft_tp_line(tp, (&(*line)));
	if ((!tp->size_buf && !*line) || (!*tp->content && !tp->size_buf && *line))
		return (0);
	// if (!*tp->content && !tp->size_buf && *line) // la ultima fila
	// 	return (0);
	else if (!ft_strchr(*line, '\n'))
		ft_buffer(fd, tp, &(*line));
	return (1);
}

char *get_next_line(int fd)
{
	static t_print *tp;
	char *line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tp)
		tp = (t_print *)malloc(sizeof(t_print) * 1);
	if (!tp)
		return (NULL);
	line = (NULL);
	ft_buffer(fd, &(*tp), &line);
	if (line)
		return (line);
	else if (!line && !((*tp)).size_buf)
	{
		if (tp)
			free(tp);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char *line;

// 	// fd = open("../test/text-copy.txt", O_RDONLY);
// 	// fd = open("../test/text.txt", O_RDONLY);
// 	fd = open("../test/multiple_line_no_nl", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
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
