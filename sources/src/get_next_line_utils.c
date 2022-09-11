/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:30 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/11 13:56:58 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "get_next_line.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

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

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;
	int		i;

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (len > (len_s - start))
		len = len_s - start;
	if (start > len_s)
		return (ft_strdup(""));
	res = (char *)malloc((len + 1) * sizeof(*s));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &((char *)s)[start], (len + 1));
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*de;
	char	*sr;
	size_t	i;

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

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

void	*ft_put_line(const char *s, int n)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(n);
	if (!tmp)
		return (NULL);
	else
	{
		i = 0;
		while (i < n)
		{
			tmp[i] = s[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

void	ft_tp_str_line(t_print *tp, char **line)
{
	char	*str;
	int		len_tp;
	char	*tmp_tp;
	int		len_line;

	str = ft_strchr(tp->content, '\n');
	len_tp = str - tp->content + 1;
	len_line = strlen(*line);
	tmp_tp = ft_put_line(tp->content, len_tp);
	str = ft_put_line(*line, len_line);
	free(*line);
	*line = (NULL);
	*line = ft_strjoin(str, tmp_tp);
	ft_cut_tp(tp, len_tp);
	free(tmp_tp);
	free(str);
}

void	ft_tp_str_lnull(t_print *tp, char **line)
{
	int		len_tp;
	char	*str;
	int		len;

	len_tp = ft_strlen(tp->content);
	len = ft_strlen(*line);
	str = ft_put_line(*line, len);
	free(*line);
	*line = (NULL);
	*line = ft_strjoin(str, tp->content);
	ft_cut_tp(tp, len_tp);
	free(str);
}

int	ft_tp_line(t_print *tp, char **line)
{
	char	*str;
	int		len;

	str = ft_strchr(tp->content, '\n');
	if (str && !*line)
	{
		len = str - tp->content + 1;
		*line = ft_put_line(tp->content, len);
		ft_cut_tp(tp, len);
	}
	else if (str && *line)
		ft_tp_str_line(tp, &(*line));
	else if (*tp->content && *line != NULL)
		ft_tp_str_lnull(tp, &(*line));
	else
	{
		len = ft_strlen(tp->content);
		*line = ft_put_line(tp->content, len);
		ft_cut_tp(tp, len);
	}
	return (1);
}

void	ft_cut_tp(t_print *tp, int len_trim)
{
	char	*str;
	int		len_tp;

	len_tp = ft_strlen(tp->content);
	str = ft_strjoin(tp->content, "");
	while (len_tp >= 0)
	{
		tp->content[len_tp] = '\0';
		len_tp--;
	}
	len_tp = 0;
	while (str[len_trim] != '\0')
	{
		tp->content[len_tp] = str[len_trim];
		len_trim++;
		len_tp++;
	}
	free(str);
}
