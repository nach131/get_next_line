/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_bzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:59:35 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/15 16:14:19 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

void	ft_bzero(void *s, size_t n)
{
	char *ch;
	size_t	i;

	ch = s;
	i = 0;
	while (i < n)
	{
		ch[i] = '\0';
		i++;
	}
}

void *ft_calloc_plus(size_t count, size_t size)
{
	void *puntero;
	char *ch;
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
	// ft_bzero(puntero, count * size);
	return (puntero);
}
void *ft_calloc(size_t count, size_t size)
{
	void *puntero;

	puntero = malloc(count * size);
	if (!puntero)
		return (NULL);
	ft_bzero(puntero, count * size);
	return (puntero);
}
typedef struct s_print
{
	char	content[BUFFER_SIZE];
	ssize_t	size_buf;
}	t_print;

int main(void)
{
	static t_print *tp;
	if (!tp)
		tp = (t_print *)ft_calloc_plus(sizeof(t_print), 1);

	write(1, "@", 1);

}
