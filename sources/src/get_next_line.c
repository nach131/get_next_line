/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/19 18:01:03 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*puntero;
	char	*ch;
	size_t	i;

	puntero = malloc(count * size);
	if (!puntero)
		return (NULL);
	ch = puntero;
	i = 0;
	while (i < (count * size))
	{
		ch[i] = '\0';
		i++;
	}
	return (puntero);
}

void	ft_tp_line_ex(t_print *tp, char **line, int len_tp, char *str)
{
	char	*tmp_tp;

	if (str && *line)
	{
		tmp_tp = (char *)ft_calloc(len_tp, sizeof(tmp_tp));
		ft_memcpy(tmp_tp, tp->content, len_tp);
		str = ft_strjoin(*line, "");
		free(*line);
		*line = ft_strjoin(str, tmp_tp);
		free(tmp_tp);
		free(str);
	}
	else
	{
		len_tp = ft_strlen(tp->content);
		str = ft_strjoin(*line, "");
		free(*line);
		*line = ft_strjoin(str, tp->content);
		free(str);
	}
	ft_cut_tp(tp, len_tp);
}

int	ft_tp_line(t_print *tp, char **line)
{
	char	*str;
	int		len_tp;

	str = ft_strchr(tp->content, '\n');
	len_tp = str - tp->content + 1;
	if (str && !*line)
	{
		str = (char *)ft_calloc(len_tp, sizeof(str));
		ft_memcpy(str, tp->content, len_tp);
		ft_cut_tp(tp, len_tp);
		*line = str;
	}
	else if (str && *line)
		ft_tp_line_ex(tp, &(*line), len_tp, str);
	else if (*tp->content && *line != NULL)
		ft_tp_line_ex(tp, &(*line), len_tp, str);
	else
	{
		len_tp = ft_strlen(tp->content);
		*line = ft_strjoin(tp->content, "");
		ft_cut_tp(tp, len_tp);
	}
	return (1);
}

int	ft_buffer(int fd, t_print *tp, char **line)
{
	int	size_buf;

	if (!*tp->content)
		size_buf = read(fd, tp->content, BUFFER_SIZE);
	if (size_buf < 0)
		return (-1);
	if (*tp->content)
		ft_tp_line(tp, (&(*line)));
	if ((!size_buf && !*line) || (!*tp->content && !size_buf && *line))
		return (0);
	else if (!ft_strchr(*line, '\n'))
		ft_buffer(fd, tp, &(*line));
	return (size_buf);
}

char	*get_next_line(int fd)
{
	static t_print	*tp;
	char			*line;
	int				size_buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tp)
		tp = (t_print *)ft_calloc(sizeof(t_print), 1);
	if (!tp)
		return (NULL);
	line = (NULL);
	size_buf = ft_buffer(fd, &(*tp), &line);
	if (line)
		return (line);
	// else if ((!line && !((*tp)).size_buf) || (*tp).size_buf < 0)
	else if ((!line && !size_buf) || size_buf < 0)
	{
		if (tp)
			free(tp);
		tp = (NULL);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char *line;

// 	// fd = open("../test/text-copy.txt", O_RDONLY);
// 	// fd = open("../test/nl", O_RDONLY);
// 	fd = open("../test/multiple_nl.txt", O_RDONLY);
// 	// close(fd);

// 	// if (fd == -1)
// 	// 	return (-1);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 		{
// 			line = get_next_line(fd);
// 			break;
// 		}
// 		else if (line)
// 		{
// 			printf("%s", line);
// 			// printf("----------------\n");
// 			if (line)
// 				free(line);
// 		}
// 	}
// 	return (1);
// }
