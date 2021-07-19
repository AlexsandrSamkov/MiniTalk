#include "../includes/server.h"

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

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

int	ft_str_error(char *s, int ret)
{
	if (!s)
		return (ret);
	write (2, s, ft_strlen(s));
	return (ret);
}

void	ft_decoder(int sig)
{
	static int	c;
	static int	power;

	if (sig == SIGUSR1)
		c += 1 << (7 - power);
	power += 1;
	if (power == 8)
	{	
		write(1, &c, 1);
		c = 0;
		power = 0;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 1)
		return (ft_str_error("Error: args", 1));
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_decoder);
	signal(SIGUSR2, ft_decoder);
	while (1)
		pause ();
	return (0);
}
