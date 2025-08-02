#include "src/sound.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int     mmfile;
    char    *content;

    mmfile = open("music.mm", O_RDONLY);
    if (mmfile < 0)
    {
        perror("open");
        return (1);
    }
    content = read_file(mmfile);
    if (!content)
    {
        perror("read_file");
        close(mmfile);
        return (1);
    }
    parse_notes(content);
    free(content);
    close(mmfile);
    return (0);
}

