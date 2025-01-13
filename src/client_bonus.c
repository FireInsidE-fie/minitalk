/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2025/01/13 12:52:53 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_ping_back(int signum)
{
	static int8_t	ping_received;

	if (!ping_received && ++ping_received)
		write(1, "Ping back received!\n", 21);
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
		write(1, "Correct usage : ./client <server pid> <data to send>\n", 54);
		return (-1);
	}
	signal(SIGUSR1, handle_ping_back);
	send_data(argv[1], argv[2]);
	pause();
	return (0);
}
