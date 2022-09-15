/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap-buffer-overflow.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:44:44 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/09/15 09:54:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define BUFFER_SIZE 10
#define BUFFER_SIZE 4
#define OVERSIZE 5

int main(void)
{
	char str[] = "42 Barcelona";
	char *mem = malloc(BUFFER_SIZE);
	// char *mem = malloc(4);

	strcpy(mem, str);

	printf("%s: esto es el string\n", mem);
	return (EXIT_SUCCESS);
}

//=============	COMPILACION ====================================================
// gcc -g3 -fsanitize=address heap-buffer-overflow.c

// ==85944==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6020000000f4 at pc 0x00010ce13d00 bp 0x7ffee2e3d6f0 sp 0x7ffee2e3ce90
// WRITE of size 13 at 0x6020000000f4 thread T0
//     #0 0x10ce13cff in wrap_strcpy (libclang_rt.asan_osx_dynamic.dylib:x86_64+0x4ecff)
//     #1 0x10cdc2ce2 in main heap-buffer-overflow.c:31
//     #2 0x7fff684e7014 in start (libdyld.dylib:x86_64+0x1014)

// 0x6020000000f4 is located 0 bytes to the right of 4-byte region [0x6020000000f0,0x6020000000f4)
// allocated by thread T0 here:
//     #0 0x10ce1a003 in wrap_malloc (libclang_rt.asan_osx_dynamic.dylib:x86_64+0x55003)
//     #1 0x10cdc2cc3 in main heap-buffer-overflow.c:28
//     #2 0x7fff684e7014 in start (libdyld.dylib:x86_64+0x1014)

// SUMMARY: AddressSanitizer: heap-buffer-overflow (libclang_rt.asan_osx_dynamic.dylib:x86_64+0x4ecff) in wrap_strcpy
// Shadow bytes around the buggy address:
//   0x1c03ffffffc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x1c03ffffffd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x1c03ffffffe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x1c03fffffff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x1c0400000000: fa fa fd fd fa fa fd fd fa fa 00 05 fa fa 00 06
// =>0x1c0400000010: fa fa 00 04 fa fa 00 00 fa fa 00 06 fa fa[04]fa
//   0x1c0400000020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x1c0400000030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x1c0400000040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x1c0400000050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x1c0400000060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
