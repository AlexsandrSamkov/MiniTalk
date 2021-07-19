#ifndef CLIENT_H
# define CLIENT_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# define ONE	0b00000001
# define TWO	0b00000010
# define THREE	0b00000100
# define FOUR	0b00001000
# define FIVE	0b00010000
# define SIX	0b00100000
# define SEVEN	0b01000000
# define EGHIT	0b10000000
void	ft_str_error(char *s);
int		ft_atop(char *s);
size_t	ft_strlen(char *s);
#endif