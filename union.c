/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:30:47 by root              #+#    #+#             */
/*   Updated: 2025/01/06 23:35:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int ft_double(char *str, char c, int index)
{
	int i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	if (ac == 3)
	{
		while(av[1][i])
		{
			if (ft_double(av[1], av[1][i], i))
				write(1, &av[1][i], 1);
			i++;
		}
		while(av[2][j])
		{
			if (ft_double(av[1], av[2][j], i) && ft_double(av[2], av[2][j], j))
				write(1, &av[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}