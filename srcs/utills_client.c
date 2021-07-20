#include "../includes/client.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_str_error(char *s)
{
	write (2, s, ft_strlen(s));
	exit (1);
}

int	ft_atop(char *s)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (i > 5)
			return (0);
		nbr *= 10;
		nbr += (int)(s[i]) - 48;
		i++;
	}
	if (nbr > 999998 || nbr < 100)
		return (0);
	return (nbr);
}
