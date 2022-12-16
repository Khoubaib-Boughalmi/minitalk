/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:45:55 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/16 15:57:02 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int spid, char c)
{
	int	bit;

	bit = __CHAR_BIT__ - 1;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			kill(spid, SIGUSR2);
		else
			kill(spid, SIGUSR1);
		usleep(200);
		bit--;
	}
}

void	send_str(int spid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_bit(spid, str[i]);
		i++;
	}
	send_bit(spid, 0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("please enter a valid server PID and a valid msg");
		return (0);
	}
	if (kill(ft_atoi(argv[1]), 0) < 0 || !ft_atoi(argv[1]))
	{
		ft_printf("PID is incorrect");
		return (0);
	}
	send_str(ft_atoi(argv[1]), argv[2]);
	return (0);
}
