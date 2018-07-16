/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:44:04 by bgres             #+#    #+#             */
/*   Updated: 2017/11/02 22:28:00 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)malloc(sizeof(char) * size + 1);
	if (a == NULL)
		return (NULL);
	if (a == NULL)
		return (NULL);
	while (i <= size)
		a[i++] = '\0';
	return (a);
}
