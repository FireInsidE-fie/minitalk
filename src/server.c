/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/25 08:20:30 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	get_data(int signum, siginfo_t *info, void *ptr)
{
	/*
	 * Get the incoming character's size (by reading the first byte, the number
	 * of 1s indicate the number of bytes used by the encoding)
	 * Then loop while getting the character bit by bit until it's done, and
	 * print the resulting UTF-8 character.
	*/
	(void)info;
	(void)ptr;
	kill(info->si_pid, SIGUSR1);
	ft_printf("signal %d received!!\n", signum);
	// In the end only use async safe functions like write to write the character
}

int		main(void)
{
	struct sigaction	minitalk;
	sigset_t			mask;

	sigemptyset(&mask);
	minitalk.sa_sigaction = get_data;
	minitalk.sa_mask = mask;
	minitalk.sa_flags = 0;
	ft_printf("[!] - Server PID : %d\n", getpid());
	sigaction(SIGUSR1, &minitalk, NULL);
	while (1)
		sleep(100);
	// Use pause() here in a loop, until a signal is received, then do some magic,
	// then pause again
}