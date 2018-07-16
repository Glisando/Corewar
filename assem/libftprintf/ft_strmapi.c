/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:55:19 by bgres             #+#    #+#             */
/*   Updated: 2017/11/04 19:16:10 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	n;
	char			*g;

	n = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i] != '\0')
		i++;
	g = (char *)malloc(sizeof(char) * (i + 1));
	if (!g)
		return (NULL);
	while (n < i)
	{
		g[n] = f(n, s[n]);
		n++;
	}
	g[n] = '\0';
	return (g);
}
