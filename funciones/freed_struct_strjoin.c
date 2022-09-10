/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed_struct_strjoin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:15:56 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/31 19:48:49 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	// free(res);
	return (res);
}

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

static void job(t_print **res)
{
	const char *str = " y mucho mas.";
	char	*str_tmp;

	str_tmp = ft_strjoin((*res)->content, str);
	(*res)->content = str_tmp;
	free(str_tmp);
}

static char *get_next_line()
{
	t_print *res;
	res = ft_new_content("42 Barcelona");

	job(&res);
	//=========================================================================
	res->content = &res->content[12];

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

// leaks -atExit -- ./freed_struct_nach.out

//===========================================================================================
// 42 Barcelona
// (null)
// Process:         freed_struct_nach.out [72970]
// Path:            /Volumes/1TB/Dropbox/00_42Barcelona/42Barcelona/C1/get_next_line/funciones/freed_struct_nach.out
// Load Address:    0x1042ef000
// Identifier:      freed_struct_nach.out
// Version:         ???
// Code Type:       X86-64
// Parent Process:  leaks [72969]

// Date/Time:       2022-08-25 21:23:06.957 +0200
// Launch Time:     2022-08-25 21:23:06.657 +0200
// OS Version:      Mac OS X 10.13.6 (17G14042)
// Report Version:  7
// Analysis Tool:   /Applications/Xcode.app/Contents/Developer/usr/bin/leaks
// Analysis Tool Version:  Xcode 10.1 (10B61)

// Physical footprint:         352K
// Physical footprint (peak):  352K
// ----

// leaks Report Version: 4.0
// Process 72970: 159 nodes malloced for 17 KB
// Process 72970: 0 leaks for 0 total leaked bytes.
//===========================================================================================
