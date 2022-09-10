/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:32:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/04 13:45:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_print
{
	char *content;
	// char *line;
	ssize_t size_buf;
} t_print;

void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_strchr(const char *s, int c);
int ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
int ft_tp_line(t_print *tp, char **line);
int ft_tp(t_print *tp);

char *get_next_line(int fd);

#endif
