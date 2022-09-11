/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// #include <unistd.h>

#define BUFFER_SIZE 5

typedef struct s_print
{
	char content[BUFFER_SIZE];
} t_print;

void *ft_put_line(const char *s, int n)
{
	char *tmp = NULL;

	tmp = (char *)malloc(n);
	if (!tmp)
		return NULL;
	else
	{
		int i = 0;
		while (i < n)
		{
			tmp[i] = s[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

void ft_put(t_print *tp)
{
	int i = 0;

	while (i < BUFFER_SIZE)
	{
		tp->content[i] = 65 + i; // Pongo ABCDE
		i++;
	}
}

void ft_cut(t_print *tp, int len)
{
	char *str;
	int i = 0;
	int len_tp = strlen(tp->content);

	str = ft_put_line(tp->content, len_tp);
	while (len_tp >= 0)
	{
		tp->content[len_tp] = '\0';
		len_tp--;
	}
	while (str[len] != '\0')
	{
		tp->content[i] = str[len];
		len++;
		i++;
	}
	free(str);
}

int main(void)
{
	static t_print *tp;

	tp = (t_print *)malloc(sizeof(t_print) * 1);
	ft_put(&(*tp));
	ft_cut(&(*tp), 3);

	printf("%s", tp->content);

	return (0);
}
