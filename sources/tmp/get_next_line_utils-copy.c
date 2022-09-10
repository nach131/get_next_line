/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils-copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:30 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/02 12:00:05 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "get_next_line.h"

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

char *ft_strdup(const char *s1)
{
	char *res;
	size_t len;
	int i;

	len = ft_strlen(s1) + 1;
	if (!s1)
		return (NULL);
	res = (char *)malloc(len * sizeof(*s1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
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
	// res[len_s1 + len_s2] = '\0';
	return (res);
}

char *ft_strjoin_len(char const *s1, char const *s2, int len_s2)
{
	char *res;
	size_t len_s1;

	len_s1 = ft_strlen(s1);
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(*res));
	if (!res)
		return (0);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	return (res);
}

// Se tendrá que separar en dos funciones
// join_one , join_two
int ft_join(char *str, t_print *tp)
{
	int i = 0;
	int len = ft_strlen(str);

	if (!str)
		return (-1);
	if (!tp->content && len)
	{
		tp->content = malloc(len);
		if (!tp->content)
			return (0);
		while (str[i] != '\0')
		{
			tp->content[i] = str[i];
			i++;
		}
		tp->content[i] = '\0';
	}
	else if (tp->content && str)
	{
		int len2 = ft_strlen(tp->content);
		char *tmp = tp->content;
		tp->content = malloc(len2 + len);
		if (!tp->content)
			return (0);
		while (i <= len2)
		{
			tp->content[i] = tmp[i];
			i++;
		}
		i = 0;
		while (str[i] != '\0')
		{
			tp->content[len2] = str[i];
			i++;
			len2++;
		}
		if (len2)
			free(tmp);
		tp->content[len2] = '\0';
	}
	return (1);
}

int ft_line(char *str, t_print *tp, int len)
{
	int i = 0;

	tp->line = malloc(len + 1);
	if (!tp->line)
		return (0);
	while (i <= len)
	{
		tp->line[i] = str[i];
		i++;
	}
	tp->line[i] = '\0';
	tp->content = (NULL);
	return (1);
}

int ft_line_two(char *str, t_print *tp)
	{
		int i = 0;
		char *tmp = tp->content;
		int len_str = ft_strlen(str);
		int len_tp = ft_strlen(tp->line);

		tp->line = malloc(len_str + len_tp);
		if(!tp->line)
			return (0);
		while(str[i] != '\0')
		{
			tp->line[len_tp] = str[i];
			i++;
			len_tp++;
		}
		free(tmp);
		tp->line[len_tp] = '\0';
	}

int ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char *ft_char_to_str(const char *s, int n)
{
	if (!s)
		return NULL;
	int i;
	char *res = NULL;
	res = (char *)malloc(n + 1);
	if (!res)
	{
		// marcar algún error
		return NULL;
	}
	else
	{
		i = 0;
		while (i < n)
		{
			res[i] = s[i];
			i++;
		}
		res[i] = '\0';
		free(res);
		return res;
	}
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' && i < n && s1[i] == s2[i])
		i++;
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
