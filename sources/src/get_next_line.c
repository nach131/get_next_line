/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/10 15:47:08 by nmota-bu         ###   ########.fr       */
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
// #define BUFFER_SIZE 5

#include "get_next_line.h"

static int ft_buffer(int fd, t_print *tp, char **line)
{
	// if (!tp->content)
	if (!*tp->content)
	{

		// tp->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		// tp->content = calloc(BUFFER_SIZE + 1, sizeof(char));
		// if (!tp->content)
		// 	return (0);
		tp->size_buf = read(fd, tp->content, BUFFER_SIZE);
		if (!tp->size_buf && *tp->content == '\0')
		{
			free(tp->content);
			// tp->content = (NULL);
		}
	}
	if (*tp->content)
		ft_tp_line(tp, (&(*line)));
	if (!tp->size_buf && !*line) // ya no hay nada
		return (0);
	if (!*tp->content && !tp->size_buf && *line) // la ultima fila
		return (0);
	else if (!ft_strchr(*line, '\n'))
		ft_buffer(fd, tp, &(*line));
	return (1);
}

// t_print *ft_lstnew(void *content)
// {
// 	t_print *new;

// 	new = (t_print *)malloc(sizeof(t_print) * 1);
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	return (new);
// }

char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	static t_print *tp;
	if (!tp)
		tp = (t_print *)malloc(sizeof(t_print) * 1);
	char *line;
	line = (NULL);
	ft_buffer(fd, &(*tp), &line);
	if (line)
		return (line);
	else if (!line && !((*tp)).size_buf)
		return (NULL);
	return (line);
}

int main()
{
	int fd;
	char *line;

	fd = open("../test/text.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		else if (line)
		{
			printf("%s", line);
			// printf("----------------\n");
			if (line)
				free(line);
		}
	}
	return (1);
}
