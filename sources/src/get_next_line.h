/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:32:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/23 13:18:35 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
int	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_char_to_str(const char *s, int n);


typedef struct s_print
{
	char *content;
} t_print;

typedef struct s_flag
{
	int	readed;
} t_flag;

char	*get_next_line(int fd);
// char	*ft_strjoin(char const *s1, char const *s2);

#endif
