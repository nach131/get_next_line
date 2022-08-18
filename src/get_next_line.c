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
#define BUFFER_SIZE 420
// 
#include "inc/get_next_line.h"

char	*get_next_line(int fd)
{
	t_print tp;
	char *buf;
	tp.to_send = "toma";


	buf = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if(!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	printf("buf\n: %s\n", buf);
	printf("fd: %i\n",fd);
	free(buf);
	return(buf);
}


int	main(void)
{
	int	fd;
	char *res;

	fd = open("text.txt", O_RDONLY);
	if (fd)
	{
		printf("File was opened\n");
	}
	res = get_next_line(fd);
	printf("res:\e[3;33m\n%s\e[0m\n", res);
}