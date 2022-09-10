/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/04 12:51:57 by nmota-bu         ###   ########.fr       */
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
#define BUFFER_SIZE 5

#include "get_next_line.h"

static int ft_buffer(int fd, t_print *tp)
{
	if (!tp->content)
	{
		tp->content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tp->content)
			return (0);
		tp->size_buf = read(fd, tp->content, BUFFER_SIZE);
		if (!tp->size_buf && *tp->content == '\0')
		{
			free(tp->content);
			tp->content = (NULL);
		}
	}
	if (tp->content)
		ft_tp_line(tp);
	if (!tp->size_buf && !tp->line) // ya no hay nada
		return (0);
	if (!tp->content && !tp->size_buf && tp->line) // la ultima fila
		return (0);
	else if (!ft_strchr(tp->line, '\n'))
		ft_buffer(fd, tp);
	return (1);
}

char *get_next_line(int fd)
{
	static t_print tp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tp.line = (NULL);
	free(tp.line);
	ft_buffer(fd, &tp);
	if (tp.line)
		return (tp.line);
	else if (!tp.line && !tp.size_buf)
		return (NULL);
	return (tp.line);
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
			free(line);
		}
	}
	return (1);
}
