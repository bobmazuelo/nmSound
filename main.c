#include "src/sound.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main()
{
	int	mmfile;
       
	mmfile = open("music.mm", O_RDONLY);
	rea_line(mmfile);
	return (0);
}
