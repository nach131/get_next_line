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
#define BUFFER_SIZE 4
//
#include "get_next_line.h"

void cambio(t_print *tp)
{

printf("aki: %s", tp->to_send);
tp->to_send = ft_strjoin(tp->to_send, "nada");
}

char *get_next_line(int fd)
{
	static char *readed;
	static t_print tp;
	char *buf;

	if (!tp.to_send)
		tp.to_send = strdup("");

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	tp.to_send = ft_strjoin(tp.to_send, buf);
	free(buf);
	if (!strchr(tp.to_send, '\n'))
		get_next_line(fd);
	return (tp.to_send);
}

int main(void)
{
	int fd;
	char *res;

	fd = open("text.txt", O_RDONLY);

	while ((res = get_next_line(fd)) != NULL)
		printf("res:\e[3;33m\n%s\e[0m\n", res);
	// res = get_next_line(fd);
}