/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:28:47 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/01 18:31:19 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

void	sig_init(int sig, void (*sighandler)(int, siginfo_t *, void *));
int		ft_atoi(char *str);
#endif