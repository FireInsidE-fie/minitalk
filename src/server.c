/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:48:45 by estettle          #+#    #+#             */
/*   Updated: 2024/11/22 15:44:53 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_received(void)
{
	char	received;

	// Set received to the signal's value
	ft_printf("%c", received);
}

int		main(void)
{
	pid_t	pid;
	char	received;

	pid = getpid();
	received = NULL;
	ft_printf("%d\n", pid);
	// Set SIGUSR1 to do the data transfering
	// Set SIGUSR2 to send back server status to the client
	// so it knows what's going on (ready, busy, error, etc)

	// Do the magic here

	ft_printf("%s\n", received);
}