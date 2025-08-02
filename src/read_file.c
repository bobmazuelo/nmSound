#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "sound.h"

/*
**  read_file
**  ---------
**  Reads the entire content from the file descriptor `fd` and returns it as a
**  NUL-terminated string. The caller is responsible for freeing the returned
**  buffer. On error, NULL is returned.
*/

char    *read_file(int fd)
{
    size_t  cap = 1024;
    size_t  len = 0;
    char    *buf = malloc(cap + 1);
    ssize_t r;

    if (!buf)
        return (NULL);
    while ((r = read(fd, buf + len, cap - len)) > 0)
    {
        len += r;
        if (len == cap)
        {
            cap *= 2;
            char *tmp = realloc(buf, cap + 1);
            if (!tmp)
            {
                free(buf);
                return (NULL);
            }
            buf = tmp;
        }
    }
    if (r < 0)
    {
        free(buf);
        return (NULL);
    }
    buf[len] = '\0';
    return (buf);
}

/*
**  parse_notes
**  -----------
**  Very small and permissive parser for the custom music notation. It
**  identifies tokens representing notes (c,d,e,f,g,a,b) optionally followed by
**  an accidental (+/-) and a duration (number). Each parsed note is printed to
**  stdout.
*/

void    parse_notes(const char *content)
{
    const char  *p = content;

    while (*p)
    {
        if (strchr("cdefgab", *p))
        {
            t_note note;

            note.note = *p++;
            note.accident = 0;
            note.duration = 4; /* default duration */
            if (*p == '+' || *p == '-')
            {
                note.accident = *p;
                p++;
            }
            if (isdigit((unsigned char)*p))
            {
                note.duration = strtol(p, (char **)&p, 10);
            }
            printf("note: %c accident: %c duration: %d\n",
                note.note,
                note.accident ? note.accident : ' ',
                note.duration);
        }
        else
            p++;
    }
}

