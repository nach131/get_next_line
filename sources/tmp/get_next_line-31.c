/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/31 20:59:08 by nmota-bu         ###   ########.fr       */
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
#define BUFFER_SIZE 20

#include "get_next_line.h"

static t_print *ft_new_content(char *content)
{
	t_print *new;

	new = (t_print *)malloc(sizeof(t_print) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	return (new);
}

// HACER FUNCIÓN QUE LEA TP Y BUFF Y DEVUELVA LA LINEA
// Y EL RESTO A TP, Y QUITE EL TP
static void ft_put(int size_buf, char *buf, t_print **res, t_print **tp)
{
	char *before;
	char *str_tmp;
	int len;
	if (size_buf)
	{
		str_tmp = ft_strjoin((*tp)->content, ft_char_to_str(buf, ft_strlen(buf)));
		(*tp)->content = str_tmp;
		free(str_tmp);
	}
	before = ft_strchr((*tp)->content, '\n');
	if (before)
	{
		len = before - (*tp)->content + 1;
		str_tmp = ft_strjoin_len((*res)->content, (*tp)->content, len);
		(*res)->content = str_tmp;
		free(str_tmp);
		(*tp)->content = &(*tp)->content[len];
	}
	else if (ft_strlen((*tp)->content))
	{
		len = ft_strlen((*tp)->content);
		str_tmp = ft_strjoin_len((*res)->content, (*tp)->content, len);
		(*res)->content = str_tmp;
		free(str_tmp);
		(*tp)->content = &(*tp)->content[len];
	}
	else if (ft_strlen((*tp)->content) == 0 && !size_buf)
	{
		(*res)->content = NULL;
	}
}

static int ft_buffer(int fd, t_print **res, t_print **tp)
{
	char *buf;
	ssize_t size_buf;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	size_buf = read(fd, buf, BUFFER_SIZE);
	ft_put(size_buf, buf, res, tp);
	// if (!size_buf && !(*tp)->content)
	// {
	// 	(*res)->content = NULL;
	// }
	free(buf);
	return (size_buf);
}

char *get_next_line(int fd)
{
	static t_print *tp;
	t_print *res;
	int size_buf;

	res = ft_new_content("");
	if (!tp)
		tp = ft_new_content("");
	// AKI SI NO HAY TP volver a cargar el buf //if (!ft_strchr(tp->content, '\n')) // cuidado con la ultima vuelta
	size_buf = ft_buffer(fd, &res, &tp);
	if (res->content == (NULL)) // poner NULL final del buf
	{
		// free(res);
		// free(tp);
		return (NULL);
	}
	else if (ft_strlen(res->content))
		return (res->content);
	else if (!ft_strchr(res->content, '\n'))
	{
		get_next_line(fd);
	}
	// free(tp);
	write(1, "@", 1);
	return (res->content);
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
		else if (line)
		{
			printf("%s", line);
			// free(line);
		}
		// free(line);
	}
	return (1);
}
