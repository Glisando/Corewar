/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:31:09 by bgres             #+#    #+#             */
/*   Updated: 2017/11/03 20:57:48 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		n;
	char	*g;

	n = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i] != '\0')
		i++;
	g = (char *)malloc(sizeof(char) * (i + 1));
	if (!g)
		return (NULL);
	while (s[n] != '\0')
	{
		g[n] = f(s[n]);
		n++;
	}
	g[n] = '\0';
	return (g);
}
