#include "../includes/client.h"

void	ft_sig_msg(pid_t pid, char n)
{
	if (n)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_str_error("Error: signal\n");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_str_error("Error: signal\n");
	}
	usleep(100);
}

void	ft_coder(pid_t pid, char c)
{
	ft_sig_msg(pid, (c & EGHIT));
	ft_sig_msg(pid, (c & SEVEN));
	ft_sig_msg(pid, (c & SIX));
	ft_sig_msg(pid, (c & FIVE));
	ft_sig_msg(pid, (c & FOUR));
	ft_sig_msg(pid, (c & THREE));
	ft_sig_msg(pid, (c & TWO));
	ft_sig_msg(pid, (c & ONE));
	usleep(100);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		ft_str_error("Error: args\n");
	pid = ft_atop(argv[1]);
	if (!pid)
		ft_str_error("Error: PID\n");
	while (argv[2][i])
		ft_coder(pid, argv[2][i++]);
	return (0);
}
