/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/12 14:41:35 by nmota-bu         ###   ########.fr       */
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

static int	ft_buffer(int fd, t_print *tp, char **line)
{
	if (!*tp->content)
		tp->size_buf = read(fd, tp->content, BUFFER_SIZE);
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
// 	fd = open("../test/empty.txt", O_RDONLY);
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
