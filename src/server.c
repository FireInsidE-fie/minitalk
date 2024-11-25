/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/25 09:38:20 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int32_t	character;

static void	get_data(int signum, siginfo_t *info, void *ptr)
{
	/*
	 * Get the incoming character's size (by reading the first byte, the number
	 * of 1s indicate the number of bytes used by the encoding)
	 * Then loop while getting the character bit by bit until it's done, and
	 * print the resulting UTF-8 character.
	*/
	(void)ptr;
	kill(info->si_pid, SIGUSR1);
	if (signum == SIGUSR1)
		character = 0;
	else
		character = 1;
}

int		main(void)
{
	struct sigaction	minitalk;
	sigset_t			mask;

	character = 0;
	sigemptyset(&mask);
	minitalk.sa_sigaction = get_data;
	minitalk.sa_mask = mask;
	minitalk.sa_flags = 0;
	ft_printf("[!] - Server PID : %d\n", getpid());
	sigaction(SIGUSR1, &minitalk, NULL);
	sigaction(SIGUSR2, &minitalk, NULL);
	while (1)
	{
		pause();
		ft_printf("%d\n", character);
	}
}