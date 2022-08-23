/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/23 17:56:56 by nmota-bu         ###   ########.fr       */
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
#define BUFFER_SIZE 21
//
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

static void ft_search(t_print *res, t_print *tp,char *buf)
{
	// write(1,"@",1);
	int len;
	char *before;
	const char *str;

	before = ft_strchr(buf, '\n');
	if (before)
	{
		len = before - buf;
		str = ft_char_to_str(buf, len);
		res->content = ft_strjoin(res->content, str);
	}
		if (before && (ft_strlen(buf) > (before - buf)))
	{
		tp->content = ft_strjoin(tp->content, before);
	}
}

static void ft_read_text(t_print **tp, t_print **res, char *buf)
{
	char *before;
	char *after;
	int len;
	t_print *tp_aux;
	t_print *tp_res;
	const char *str;

	tp_res = *res;
	tp_aux = *tp;

	if (ft_strlen(tp_aux->content))
	{
		tp_res->content = ft_strjoin(tp_res->content, tp_aux->content);
		before = ft_strchr(tp_aux->content, '\n');
	}

	//===========copia toda la linea y el resto lo pone en tp======================================

	ft_search(*res, *tp, buf);
	// ft_search(*res, *tp, tp_aux->content);

	//===========================================================================================
	// before = ft_strchr(buf, '\n');
	// if (before) // comprobamos que en el buffer hay mínimo una linea y la add a tp->content
	// {
	// 	len = before - buf;
	// 	// pasar la linea a const char
	// 	str = ft_char_to_str(buf, len);
	// 	tp_res->content = ft_strjoin(tp_res->content, str);
	// 	tp_res->content = ft_strjoin(tp_res->content, "\n");
	// }
	// if (before && (ft_strlen(buf) > (before - buf)))
	// {
	// 	tp_aux->content = ft_strjoin(tp_aux->content, before);
	// }
	//===========================================================================================
}

char *get_next_line(int fd)
{
	// static char *readed;
	static t_print *tp;
	t_print *res;
	char *buf;

	res = ft_new_content("");

	if (!tp)
		tp = ft_new_content("");
	// tp.content = ft_strdup("");

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	if (*buf == '\0')
	{
		// tp.content = ft_strdup("");
		return (NULL);
	}
	ft_read_text(&tp, &res, buf);
	// AKI SEPARA BUF LA LINEA como en ft_printf
	// tp.content = ft_strjoin(tp.content, buf);
	free(buf);
	if (!ft_strchr(res->content, '\n'))
		get_next_line(fd);

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
