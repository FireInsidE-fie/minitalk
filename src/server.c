/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2025/01/13 12:53:23 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int8_t	g_character;

static void	get_data(int signum, siginfo_t *info, void *ptr)
{
	static int8_t	bit_counter;

	if (g_character < 0)
	{
		g_character = 0;
		bit_counter = 7;
	}
	(void)ptr;
	if (signum == SIGUSR1)
		g_character = (g_character << 1) | 0;
	else
		g_character = (g_character << 1) | 1;
	if (--bit_counter < 0)
	{
		write(1, &g_character, 1);
		g_character = 0;
		bit_counter = 7;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	minitalk;
	sigset_t			mask;

	g_character = -1;
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
