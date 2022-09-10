/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed_struct_trim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:05:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/31 12:15:41 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_print
{
	char *content;
} t_print;

static t_print *ft_new_content(char *content)
{
	t_print *new;

	new = (t_print *)malloc(sizeof(t_print) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	return (new);
}

int ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char *ft_strjoin_len(char const *s1, char const *s2, int len_s2)
{
	char *res;
	size_t len_s1;
	// size_t len_s2;

	len_s1 = ft_strlen(s1);
	// len_s2 = ft_strlen(s2);
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(*res));
	if (!res)
		return (0);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	free(res);
	return (res);
}

static char *get_next_line()
{
	t_print *res;
	t_print *tp;

	tp = ft_new_content("42 Barcelona");
	res = ft_new_content("");
	res->content = ft_strjoin_len(res->content, tp->content, 2);


	//=========================================================================
	// res->content = &res->content[12];

	// 	//========== esto para salir
	// 	res->content = NULL;
	// 	if (res->content == (NULL)) // ESTO PARA EL FINAL
	// 	{
	// //		write(1, "ok", 2);
	// 		free(res);
	// 		return (NULL);
	// 	}
	// 	//=====================================================================

	return (res->content);
}

int main(void)
{
	char *line;

	line = get_next_line();
	printf("\e[3;32m%s\n\e[0m", line);
}
