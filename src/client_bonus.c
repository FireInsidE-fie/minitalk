/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2024/12/11 14:49:16 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int8_t	ping_received;

void	handle_ping_back(int signum)
{
	if (!ping_received && ++ping_received)
		ft_printf("Ping back received!\n");
	(void)signum;
}

void	send_data(const char *pid, const char *data)
{
	int	i;
	int	target;

    target = ft_atoi(pid);
	while (*data)
	{
		i = 31;
		while (i >= 0)
		{
			if (((*data >> i--) & 1) == 0)
				kill(target, SIGUSR1);
			else
				kill(target, SIGUSR2);
			pause();
			usleep(50);
		}
		data++;
	}
}

int	main(const int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Correct usage : ./client <server pid> <data to send>\n");
		return (-1);
	}
	ping_received = 0;
	signal(SIGUSR1, handle_ping_back);
	send_data(argv[1], argv[2]);
	return (0);
}
