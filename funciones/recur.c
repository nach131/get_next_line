/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:28:23 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/27 13:03:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>

int ft_suma(void)
{
	static int i = 0;
	if (!i)
	{
		i++;
		return (i);
	}
	// while(i < 1)
	// {
	// i++;
	// }

	return (i);
}

int main(void)
{
	int a;

	while (ft_suma() < 2)
	{
		// printf("aki");
		write(1, "!", 1);
	}
}
