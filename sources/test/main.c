/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:54:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/19 19:54:35 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <fcntl.h>
#include <stdio.h>
#include "../inc/get_next_line.h"

int main(void)
{
	int fd;
	char *res;

	fd = open("text.txt", O_RDONLY);
	if (fd)
	{
		printf("File was opened\n");
	}
	while ((res = get_next_line(fd)) != NULL)
		printf("res:\e[3;33m\n%s\e[0m\n", res);
	// res = get_next_line(fd);
}