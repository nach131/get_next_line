/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:41:15 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/25 21:12:08 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_foo {
	int	a;
	char	*b;
} t_foo;

int main(void)

{
	t_foo mystruct;
	mystruct.a = 1;
	mystruct.b = malloc(12);

	strcpy(mystruct.b, "42\n");

	/* do something clever with mystruct.b */
	printf("len: %lu\n%s\n", strlen(mystruct.b), mystruct.b);

//  free(mystruct.b);

	// while(*mystruct.b != '\n') // ASI SI
	// {
	// 	mystruct.b++;
	// 	mystruct.a++;
	// }
  return 0;
}
