/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2025/01/13 13:47:54 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int8_t	g_character;

static void	get_data(int signum)
{
	static int8_t	bit_counter;

	if (g_character < 0)
	{
		g_character = 0;
		bit_counter = 7;
	}
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
}

int	main(void)
{
	g_character = -1;
	ft_printf("[!] - Server PID : %d\n", getpid());
	signal(SIGUSR1, get_data);
	signal(SIGUSR2, get_data);
	while (1)
		sleep(1);
}
