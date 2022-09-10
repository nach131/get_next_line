/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_pas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:52:06 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/01 01:05:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>

static void job1(char *s)
{
	// s = "b";
	printf("%s", s);
}

static void job2(char **s)
{

	printf("%s", s);
}

static void job(char **s)
{
	job1(*s);
	job2(*s);
	*s = "$";
	// printf("\t%s", *s);
}

int main(void)
{
	char *str = "a";
	job(&str);
	printf("%s\n", str);
}
