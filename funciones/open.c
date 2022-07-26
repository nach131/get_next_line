/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:19:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/05 08:39:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// int open(const char *pathname, int flags);
// ssize_t read(int fd, void *buf, size_t count);
// int close(int fd);

		// printf("\e[3;33mcount ini %d \e[0m\n", count);
		// printf("\e[3;31mlen %d \e[0m\n", tp->len);
		// printf("\e[1;34mwidht %d \e[0m\n", tp->widht);

#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	char *buf;

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
	printf("\e[3;33mres:\n %s \e[0m\n", res);
}