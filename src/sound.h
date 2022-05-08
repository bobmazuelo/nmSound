#ifndef SOUND_H
# define SOUND_H

typedef struct s_note {
	char	note;		// a b c d e f g
	char	accident;	// +(sharp) -(flat)
	int	duration;	//x1 x2 x4 x6 x8 x16 ...
}	t_note;

char	*read_file(int fd);
#endif
