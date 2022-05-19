#include "src/sound.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	mmfile;
       
	if (argc != 1)
		raise("No file");
	else
	{
		mmfile = open(argv[1], O_RDONLY);
		read_file(mmfile);
	}
	return (0);
}
