/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed_struct_nach.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:15:56 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/25 21:24:54 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <fcntl.h>
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

int main(void)
{
	t_print *res;

	res = ft_new_content("42 Barcelona");
	printf("%s\n", res->content);
	res->content = NULL;
	free(res); // para liberar la estructura
	printf("%s\n", res->content);
}

// clang freed_struct_nach.c -o freed_struct_nach.out
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
