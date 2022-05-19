#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "sound.h"

char	*read_fine(int fd);

static int	get_notes();
static int	get_duration();
