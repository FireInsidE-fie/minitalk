/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/25 15:40:09 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int32_t	character;

static void	get_data(int signum, siginfo_t *info, void *ptr)
{
	static uint8_t	bit_counter;
	/*
	 * Get the incoming character's size (by reading the first byte, the number
	 * of 1s indicate the number of bytes used by the encoding)
	 * Then loop while getting the character bit by bit until it's done, and
	 * print the resulting UTF-8 character.
	*/
	if (!character || !bit_counter)
	{
		write(1, &character, 4);
		character = 0;
		bit_counter = 31;
	}
	(void)ptr;
	kill(info->si_pid, SIGUSR1);
	if (signum == SIGUSR1)
	{
		write(1, "Received 0 btw\n", 15);
		character = (character >> bit_counter) & 1;
	}
	else
	{
		write(1, "Received 1 btw\n", 15);
		character = (character >> bit_counter) & 0;
	}
	bit_counter--;
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
		//ft_printf("%d\n", character);
	}
}