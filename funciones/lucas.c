#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define TRUE 1
#define FALSE 0

int	max_malloc;
int err_malloc;
int	reset;

void *ft_malloc(size_t size)
{
	static	int	num_malloc = 0;

	if (reset)
	{
		reset = 0;
		num_malloc = 0;
	}
	if (err_malloc == 0)
		max_malloc++;
	//printf("\n Malloc num: %i \n", ++num_malloc);
	++num_malloc;
	if (num_malloc == err_malloc)
	{
		printf("\n Failed malloc num: %i \n", err_malloc);
		return (NULL);
	}
	else
		return (malloc(size));
}

void	test_gnl(int j, char *filename)
{
	int		fd;
	int		i;
	char *my_line;
	int		end;

	printf("\n\n");
	printf("================================================================================\n");
	printf("TEST NUM %i WITH %s\n", j, filename);
	printf("================================================================================\n");
	err_malloc = 0;
	reset = 1;
	fd = open(filename, O_RDONLY);
	i = 1;
	end = FALSE;
	while (end == FALSE)
	{
		my_line = get_next_line(fd);
		printf("Out %d:  %s", i, my_line);
		if (my_line)
		{
			free(my_line);
			my_line = NULL;
		}
		else
			end = TRUE;
		i++;
	}
	close(fd);
	printf("\n Num of mallocs %i \n", max_malloc);
	sleep(3);
	while (err_malloc++ < max_malloc)
	{
		printf("\n \n Checking %s with malloc fails\n", filename);
		printf("Expected failed malloc %i of %i\n", err_malloc, max_malloc);
		reset = 1;
		fd = open(filename, O_RDONLY);
		i = 1;
		end = FALSE;
		while (end == FALSE)
		{
			my_line = get_next_line(fd);
			printf("Out %d:  %s", i, my_line);
			if (my_line)
			{
				free(my_line);
				my_line = NULL;
			}
			else
				end = TRUE;
			i++;
		}
		close(fd);
	}
	max_malloc = 0;
}

int	main(void)
{
	// test_gnl(0, NULL);
	// sleep(2);
	// test_gnl(1, "");
	// sleep(2);
	test_gnl(2, "../test/multiple_line_no_nl");
	// sleep(3);
	// test_gnl(0, "1char.txt");
	// sleep(3);
	// test_gnl(0, "empty.txt");
	// sleep(3);
	// test_gnl(0, "giant_line_nl.txt");
	// sleep(3);
	// test_gnl(0, "lines_around_10.txt");
	// sleep(3);
	// test_gnl(0, "multiple_nl.txt");
	// sleep(3);
	// test_gnl(0, "one_line_no_nl.txt");
	// sleep(3);
	// test_gnl(0, "only_nl.txt");
	// sleep(3);
	// test_gnl(0, "variable_nls.txt");
	// sleep(15);
	// ​system( "read -n 1 -s -p \"Press any key to continue...\"" );
}