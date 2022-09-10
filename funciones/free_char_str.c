/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:29:24 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/29 23:53:03 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_char_to_str(const char *s, int n)
{
	int		i;
	char	*res;

	if (!s)
		return NULL;
	res = (char *)malloc(n + 1);
	if (!res)
		return NULL;
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

int main(void)
{
	char *buf = "42 Barcelona";
	const char *str;

	str = ft_char_to_str(buf, strlen(buf));

	printf("%s", str);
}


// 42 Barcelona
// Process:         a.out [13071]
// Path:            /Volumes/1TB/Dropbox/00_42Barcelona/42Barcelona/C1/get_next_line/funciones/a.out
// Load Address:    0x10e418000
// Identifier:      a.out
// Version:         ???
// Code Type:       X86-64
// Parent Process:  leaks [13070]

// Date/Time:       2022-08-29 23:52:43.466 +0200
// Launch Time:     2022-08-29 23:52:43.151 +0200
// OS Version:      Mac OS X 10.13.6 (17G14042)
// Report Version:  7
// Analysis Tool:   /Applications/Xcode.app/Contents/Developer/usr/bin/leaks
// Analysis Tool Version:  Xcode 10.1 (10B61)

// Physical footprint:         352K
// Physical footprint (peak):  352K
// ----

// leaks Report Version: 4.0
// Process 13071: 159 nodes malloced for 17 KB
// Process 13071: 0 leaks for 0 total leaked bytes.
