#include "src/sound.h"

int	main(int argc, char **argc)
{
	int	mmfile;
       
	mmfile = open("music.mm", O_RDONLY);
	read_line(mmfile);
	return (0);
}
