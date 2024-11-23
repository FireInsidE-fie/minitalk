/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/23 14:05:13 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	process_request(int signum)
{
	//pid_t	client_pid;
	//char	received;

	/* Encoding will be as follows : First a few bytes that contain the client's
	 * PID so the server can send back its answer, then the data we're
	 * transfering.
	*/
	// Set received to the signal's value
	(void)signum;
	ft_printf("signal %d received!!\n", signum);
}

int		main(void)
{
	pid_t	pid;
	char	*received;

	pid = getpid();
	received = NULL;
	ft_printf("[!] - Server PID : %d\n", pid);
	signal(SIGUSR1, process_request);
	// Set SIGUSR2 to send back server status to the client
	// so it knows what's going on (ready, busy, error, etc)

	// Wait for an interrupt signal or whatever (miiiiiight exist a better way to do this)
	while (1)
		;

	ft_printf("%s\n", received);
}