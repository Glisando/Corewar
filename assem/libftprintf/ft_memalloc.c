/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:02:22 by bgres             #+#    #+#             */
/*   Updated: 2017/11/03 22:47:32 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	while (i < size)
		a[i++] = 0;
	return (a);
}
