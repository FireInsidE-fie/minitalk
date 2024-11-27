/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2024/11/27 13:32:01 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_ping_back(int signum)
{
	(void)signum;
}

void	send_data(const char *pid, const char *data)
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
			usleep(10);
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
	signal(SIGUSR1, handle_ping_back);
	send_data(argv[1], argv[2]);
	usleep(50000);
	return (0);
}
