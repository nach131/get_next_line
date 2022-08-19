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
#include "inc/get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	size_t len_s1;
	size_t len_s2;

	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(*res));
	if (!res)
		return (0);
	res[0] = '\0';
	memcpy(res, s1, len_s1);
	memcpy(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	return (res);
}

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