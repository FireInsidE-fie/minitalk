/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2024/11/26 18:18:22 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ping_received(int signum)
{
	(void)signum;
	//ft_printf("Ping back received!!\n");
}

void	send_data(char *pid, char *data)
{
	int	i;
	int	target;

	while (*data)
	{
		i = 31;
		target = ft_atoi(pid);
		ft_printf("Sent : ");
		while (i >= 0)
		{
			if (((*data >> i--) & 1) == 0 && ft_printf("0"))
				kill(target, SIGUSR1);
			else if (ft_printf("1"))
				kill(target, SIGUSR2);
			pause();
		}
		data++;
		ft_printf("\n");
	}
}

int	main(const int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Correct usage : ./client <server pid> <data to send>\n");
		return (-1);
	}
	ft_printf("[!] - Client PID : %d\n", getpid());
	signal(SIGUSR1, ping_received);
	send_data(argv[1], argv[2]);
	usleep(50000);
	return (0);
}
