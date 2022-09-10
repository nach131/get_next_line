/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed_struct_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:31:44 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/31 19:41:59 by nmota-bu         ###   ########.fr       */
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

char *ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	size_t len_s1;
	size_t len_s2;

	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(*res));
	if (!res)
		return (0);
	memcpy(res, s1, len_s1);
	memcpy(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	// free(res);
	return (res);
}

void ft_join( t_print **tp, t_print **res)
{
	char *str;

	str = ft_strjoin((*tp)->content, (*res)->content);


}

static char *get_next_line()
{
	t_print *res;
	t_print *tp;
	const char *str = " mucho mas...";

	res = ft_new_content("42");
	tp = ft_new_content(" Barcelona");


	ft_join(&tp, &res);

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
