/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/18 17:30:19 by nmota-bu         ###   ########.fr       */
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
#define BUFFER_SIZE 42
//
#include "get_next_line.h"

static void	ft_free_tp(t_print *tp)
{
	// free(tp->to_send);
	printf("%s",tp->to_send);
	return;
}

char *get_next_line(int fd)
{
	// static char *readed;
	static t_print tp;
	char *buf;

	if (!tp.to_send)
		tp.to_send = ft_strdup("");

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	if (*buf == '\0')
	{
		// tp.to_send = ft_strdup("");
		// free(tp.to_send);
		ft_free_tp(&tp);
		return (NULL);
		// return (tp.to_send);
	}
	// AKI SEPARA BUF LA LINEA como en ft_printf
	tp.to_send = ft_strjoin(tp.to_send, buf);
	free(buf);
	if (!ft_strchr(tp.to_send, '\n'))
		get_next_line(fd);

	return (tp.to_send);
}

int main()
{
	int fd;
	char *line;

	fd = open("../test/text.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}

// int main(void)
// {
// 	int fd;
// 	char *res;

// 	fd = open("../test/text.txt", O_RDONLY);
// 	if (fd)
// 	{
// 		printf("File was opened\n");
// 	}
// 	while ((res = get_next_line(fd)) != NULL)
// 		printf("res:\e[3;33m\n%s\e[0m\n", res);
// 	// res = get_next_line(fd);
// }