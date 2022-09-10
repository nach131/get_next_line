/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:30 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/04 12:35:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "get_next_line.h"
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *de;
	char *sr;
	size_t i;

	de = (char *)dest;
	sr = (char *)src;
	i = 0;
	if (sr || de)
	{
		while (i < n)
		{
			de[i] = sr[i];
			i++;
		}
		return (de);
	}
	return (NULL);
}

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	size_t len_s1;
	size_t len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(*res));
	if (!res)
		return (0);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	return (res);
}

int ft_tp_line(t_print *tp)
{
	char *str;
	int len;
	int i;

	str = ft_strchr(tp->content, '\n');
	if (str && !tp->line)
	{
		len = str - tp->content;
		tp->line = malloc(len + 1);
		if (!tp->line)
			return (0);
		i = 0;
		while (i <= len)
		{
			tp->line[i] = tp->content[i];
			i++;
		}
		tp->line[i] = '\0';
		while (i)
		{
			tp->content++;
			i--;
		}
	}
	else if (str && tp->line)
	{
		char *tmp;
		int len_tp = str - tp->content;
		int len_line = strlen(tp->line);

		tmp = ft_strjoin("", tp->line);
		int i;
		int j;
		tp->line = (NULL);
		free(tp->line);
		tp->line = malloc(len_tp + len_line + 1);
		i = 0;
		while (i < len_line)
		{
			tp->line[i] = tmp[i];
			i++;
		}
		j = 0;
		while (tp->content[j] != '\n')
		{
			tp->line[i] = tp->content[j];
			i++;
			j++;
			// tp->content++;
		}
		tp->line[i] = '\n';
		j++;
		while (j)
		{
			tp->content++;
			j--;
		}
		tmp = (NULL);
		free(tmp);
	}
	else
	{
		ft_tp(tp);
	}
	if (ft_strlen(tp->content) && ft_strchr(tp->line, '\n'))
		return (1);
	tp->content = (NULL);
	free(tp->content);
	return (1);
}

int ft_tp(t_print *tp)
{
	char *tmp;

	if (tp->line == NULL)
		tp->line = "";
	tmp = ft_strjoin("", tp->line);
	tp->line = (NULL);
	free(tp->line);
	tp->line = ft_strjoin(tmp, tp->content);
	tmp = (NULL);
	free(tmp);
	return (1);
}
