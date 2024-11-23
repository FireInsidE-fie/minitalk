/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/23 23:15:26 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	process_request(const int signum)
{
	/* Acknowledge the client's request by sending back SIGUSR1 (how to get the
	 * client's pid? something about sigaction's struct?)
	 * Get the incoming character's size (by reading the first byte, the number
	 * of 1s indicate the number of bytes used by the encoding)
	 * Then loop while getting the character bit by bit until it's done, and
	 * print the resulting UTF-8 character.
	*/
	(void)signum;
	ft_printf("signal %d received!!\n", signum);
	// In the end only use async safe functions like write to write the character
}

int		main(void)
{
	sigset_t	*mask;
	pid_t		pid;

	mask = malloc(sizeof(sigset_t));
	if (!mask)
		return (-1);
	sigemptyset(mask);
	pid = getpid();
	ft_printf("[!] - Server PID : %d\n", pid);
	signal(SIGUSR1, process_request);

	while (1)
		sleep(100);
}