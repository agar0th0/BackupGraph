#include <unistd.h>
#include <stdio.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include <stddef.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid number of arguments\n");
		return 1;
	}
	int i = 0;	
	char chunk[3] = { 0, 0, 0 };
	int our_fd = open(argv[1], O_RDONLY);
	if (our_fd == -1)
	{
		printf("Could not open file\n");
		return 1;
	}
	char ch = 0;
	int nread = read(our_fd, &ch, 1);
	while (1)
	{
		if (i % 2 == 0)
			i = 0;
		if (nread == 0)
			break;
		nread = read(our_fd, &ch, 1);
//		printf("%c", ch);	
		if (ch != ' ' && ch != '\f' && ch != '\r' && ch != '\n' && ch != '\t' && ch != '\v')
			chunk[i] = ch;
		i += 1;
	}
	close(our_fd);
	if (chunk[0] == 0 || chunk[1] == 0)
	{
		printf("File is not long enough\n");
		return 1;
	}

	chunk[2] = '\n';
	write(STDOUT_FILENO, chunk, 3);
	
	return 0;
}
