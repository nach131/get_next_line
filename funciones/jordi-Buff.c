/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jordi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:35:25 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/08 10:49:30 by nmota-bu         ###   ########.fr       */
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
	char *line;
} t_print;

static int ft_join(char *str, t_print *tp)
{
	int i = 0;
	int len = strlen(str);
	if (!str)
		return (-1);
	if (!tp->content && len)
	{
		tp->content = (char *)calloc(len, 1);
		//	exit(1);
		// char *hola = malloc(500);
		while (str[i] != '\0')
		{
			tp->content[i] = str[i];
			i++;
		}
		tp->content[i] = '\0';
	}
	else if (tp->content && str)
	{
		int len2 = strlen(tp->content);
		char *tmp = tp->content;
		tp->content = (char *)calloc(len2 + len, 1);
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
		free(tmp);
		tp->content[len2] = '\0';
	}
	printf("%d\n", getpid());
	i = 0;
	while(i < 10)
	{
		sleep(1);
		i++;
	}
	return (1);
}

static int ft_line(char *str, t_print *tp, int len)
{
	int i = 0;

	tp->line = (char *)calloc(len + 1, 1);
	while (i <= len)
	{
		tp->line[i] = str[i];
		tp->content++;
		i++;
	}
	tp->line[i] = '\0';
	return (1);
}

static char *get_next_line()
{
	static t_print tp;
	int len;
	char *str = "Bar\n";
	ft_join(str, &tp);
	ft_join(str, &tp);

	str = strchr(tp.content, '\n');
	if (str)
	{
		len = str - tp.content;
		ft_line(tp.content, &tp, len);
	}
	return (tp.line);
}

int main(void)
{
	char *line;

	line = get_next_line();
	printf("\e[3;32m%s\n\e[0m", line);
	// free(line);
	int i = 0;
	printf("%d\n", getpid());
		line = NULL;
	while(i < 10)
	{
		sleep(1);
		i++;
	}

}
