/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:51:51 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/08/18 13:06:19 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>

int	main(void)
{
	if (BUFFER_SIZE <= 0)
		return (0);
	printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
	return (BUFFER_SIZE);
}

// gcc buffer_size.c -D BUFFER_SIZE=42
// para comprobar el valor de retorno en shell
// echo $?
