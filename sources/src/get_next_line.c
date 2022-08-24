/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/23 21:18:08 by nmota-bu         ###   ########.fr       */
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
#define BUFFER_SIZE 1

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

void	del(void *tmp)
{
   free(tmp);
}

void	ft_clear(t_print **tp, void (*del)(void*))
{
	t_print	*l_aux;

	if (tp)
	{
		while (*tp)
		{
			// l_aux = (*tp)->next;
			del((*tp)->content);
			free(*tp);
			// *tp = l_aux;
		}
			*tp = l_aux;
	}
}

static void ft_search(t_print *res, t_print *tp, char *buf, t_flag *flag)
{
	int len;
	char *before;
	const char *str;

	before = ft_strchr(buf, '\n');

	if (before && ft_strlen(before) > 1)
	{
		len = before - buf;
		str = ft_char_to_str(buf, len); // podria sumar '\n' si no tiene
		res->content = ft_strjoin(res->content, str);
		res->content = ft_strjoin(res->content, "\n");
		before++;
		flag->readed = 1;
	}
	else
	{
		tp->content = ft_strjoin(tp->content, buf);
		flag->readed = 1;
		// AKI borrar lo que se junto
	}
	if (before && (ft_strlen(buf) > (before - buf)) && flag->readed == 0)
	{
		if (ft_strlen(tp->content) > 0)
		{
			while (len)
			{
				tp->content++;
				len--;
			}
			tp->content++;
		}
		// AKI se mezlan los dos tp->content
		// tp->content = ft_strjoin(tp->content, before);
	}
}

static void ft_read_text(t_print **tp, t_print **res, char *buf, t_flag *flag)
{

	if (flag->readed == 1)
	{
		ft_search(*res, *tp, buf, flag);
	}
	else if (ft_strlen((*tp)->content))
	{
		ft_search(*res, *tp, (*tp)->content, flag);
	}
	if (!flag->readed)
		ft_search(*res, *tp, buf, flag);
	if (ft_strchr((*tp)->content, '\n'))
	{
		(*res)->content = ft_strjoin((*res)->content, (*tp)->content);
		flag->readed = 0;
	}
}

char *get_next_line(int fd)
{
	static t_print *tp;
	t_print *res;
	static t_flag flag;
	char *buf;

	res = ft_new_content("");

	if (!tp)
		tp = ft_new_content("");

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	if (*buf == '\0')
	{
		return (NULL);
	}
	ft_read_text(&tp, &res, buf, &flag);
	// AKI SEPARA BUF LA LINEA como en ft_printf
	free(buf);
	if (!ft_strchr(res->content, '\n'))
		get_next_line(fd);
	// vaciar tp y free
	ft_clear(&tp, del);
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
