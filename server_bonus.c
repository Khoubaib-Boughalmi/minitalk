/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:45:44 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/15 15:16:50 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_sig_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	byte = 0;
	static int				bit = -1;
	static int				prev = 0;

	if (info->si_pid != prev)
	{
		byte = 0;
		bit = -1;
	}
	(void)context;
	if (bit < 0)
		bit = __CHAR_BIT__ - 1;
	if (sig == SIGUSR1)
		byte &= ~(1 << bit);
	else if (sig == SIGUSR2)
		byte |= (1 << bit);
	if (!bit && byte)
		ft_printf("%c", byte);
	if (!bit && !byte)
	{
		usleep(200);
		kill(info->si_pid, SIGUSR1);
	}
	bit--;
	prev = info->si_pid;
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void) argc;
	(void) argv;
	pid = getpid();
	sig_init(SIGUSR1, &server_sig_handler);
	sig_init(SIGUSR2, &server_sig_handler);
	ft_printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}
