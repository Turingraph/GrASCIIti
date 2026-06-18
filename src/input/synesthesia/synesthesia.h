#ifndef SYNESTHESIA_H
# define SYNESTHESIA_H

# include "../get_next_line/get_next_line.h"
# include "../../utils/libft/libft.h"
# include "../../utils/type/type.h"

// default.c
t_synesthesia	free_synesthesia(t_synesthesia table);
t_synesthesia	init_default_synesthesia();

// input.c
t_synesthesia	file_to_synesthesia(int fd);

// utils.c
void			replace_char(char *dst, char before, char after);
void			synesthesia_warning(char err, char alphabet);
void			synesthesia_warning_02(char *line, char *dict);
void			write_synesthesia(int fd, t_synesthesia src);

#endif
