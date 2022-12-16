/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:45:41 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/16 16:26:34 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_init(int sig, void (*sighandler)(int, siginfo_t *, void *))
{
	struct sigaction	act;

	act.sa_sigaction = sighandler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if (sig == SIGUSR1)
		sigaction(SIGUSR1, &act, 0);
	else if (sig == SIGUSR2)
		sigaction(SIGUSR2, &act, 0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	while (str[i] != '\0')
	{
		val *= 10;
		val += str[i] - '0';
		i++;
	}
	return (val);
}
