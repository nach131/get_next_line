/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:32:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/13 16:17:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_print
{
	char	content[BUFFER_SIZE];
	ssize_t	size_buf;
}	t_print;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

void	*ft_put_line(const char *s, int n);
void	ft_tp_line_ex(t_print *tp, char **line, int len_tp, char *str);
int		ft_tp_line(t_print *tp, char **line);
void	ft_cut_tp(t_print *tp, int len_trim);

int		ft_buffer(int fd, t_print *tp, char **line);
char	*get_next_line(int fd);

#endif
