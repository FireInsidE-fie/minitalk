/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/23 16:52:43 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	process_request(const int signum)
{
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

	while (1)
		sleep(100);
}