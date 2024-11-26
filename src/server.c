/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/26 13:59:30 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/minitalk.h"

int32_t	character;

/*
static void	print_character_bin32(int32_t character) //debug
{
	int32_t	i;

	i = 31;
	while (i >= 0)
	{
		if (((character >> i) & 1) == 0)
			ft_printf("0");
		else
			ft_printf("1");
		i--;
	}
	ft_printf("\n");
}
*/

static void	get_data(int signum, siginfo_t *info, void *ptr)
{
	static int16_t	bit_counter;

	if (character < 0)
	{
		//write(1, "null reset!\n", 12); //debug
		character = 0;
		bit_counter = 31;
	}
	(void)ptr;
	// need to implement the ping back some other way
	if (signum == SIGUSR1)
	{
		//write(1, "Received 0 btw\n", 15); //debug
		character = (character << 1) | 0;
	}
	else
	{
		//write(1, "Received 1 btw\n", 15); //debug
		character = (character << 1) | 1;
	}
	//print_character_bin32(character); //debug
	//ft_printf("%d\n------\n", bit_counter); //debug
	if (--bit_counter < 0)
	{
		write(1, &character, 1);
		character = 0;
		bit_counter = 31;
	}
	usleep(20);
	kill(info->si_pid, SIGUSR1);
}

int		main(void)
{
	struct sigaction	minitalk;
	sigset_t			mask;

	character = -1;
	sigemptyset(&mask);
	minitalk.sa_sigaction = get_data;
	minitalk.sa_mask = mask;
	minitalk.sa_flags = SA_SIGINFO;
	ft_printf("[!] - Server PID : %d\n", getpid());
	sigaction(SIGUSR1, &minitalk, NULL);
	sigaction(SIGUSR2, &minitalk, NULL);
	while (1)
		pause();
}