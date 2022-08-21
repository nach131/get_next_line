/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:41:15 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/21 10:56:22 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct foo {
  int	a;
  char	*b;
} foo;

int main(void)

{
  foo mystruct;
  mystruct.a = 1;
  mystruct.b = malloc(10);

  strcpy(mystruct.b, "hello");

  /* do something clever with mystruct.b */
  printf("len: %lu\n%s\n", strlen(mystruct.b), mystruct.b);

  free(mystruct.b);
  return 0;
}
