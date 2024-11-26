/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/26 10:42:30 by estettle         ###   ########.fr       */
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
	/*
	 * Get the incoming character's size (by reading the first byte, the number
	 * of 1s indicate the number of bytes used by the encoding)
	 * Then loop while getting the character bit by bit until it's done, and
	 * print the resulting UTF-8 character.
	*/
	if (character < 0)
	{
		//write(1, "null reset!\n", 12); //debug
		character = 0;
		bit_counter = 31;
	}
	(void)ptr;
	kill(info->si_pid, SIGUSR1);
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
	bit_counter--;
	if (bit_counter < 0)
	{
		write(1, &character, 1);
		character = 0;
		bit_counter = 31;
	}
}

int		main(void)
{
	struct sigaction	minitalk;
	sigset_t			mask;

	character = -1;
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