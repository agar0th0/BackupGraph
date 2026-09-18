#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <err.h>
#include <errno.h>
#include <assert.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	
	FILE *inputF;

	inputF = fopen(argv[1], "r"); 

	int stepafter = 0;

	ssize_t check = getdelim(";",32, inputF);

	while (check != -1)
	{
		check = getdelim(";",32, inputF);
		putchar();
	}

	fclose(inputF);

	return 0;
}

