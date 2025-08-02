#ifndef SOUND_H
# define SOUND_H

typedef struct s_note
{
    char    note;      // c d e f g a b
    char    accident;  // +(sharp) -(flat)
    int     duration;  // c1 d2 e4 f6 g8 a16 ...
}   t_note;

char    *read_file(int fd);
void    parse_notes(const char *content);

#endif

