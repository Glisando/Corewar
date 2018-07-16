/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:08:10 by bgres             #+#    #+#             */
/*   Updated: 2017/11/04 19:46:36 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		pchar('-', fd);
		if (n <= -10)
			ft_putnbr_fd((n / -10), fd);
		pchar((-(n % 10) + '0'), fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		pchar(((n % 10) + '0'), fd);
	}
	else
		pchar((n + '0'), fd);
}
