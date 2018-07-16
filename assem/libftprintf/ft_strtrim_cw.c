/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:06:07 by bgres             #+#    #+#             */
/*   Updated: 2017/11/03 21:08:35 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_cw(char *s)
{
	unsigned int	start;
	unsigned int	end;
	char			*tmp;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (NULL);
	end = start;
	while (s[end] != '\0')
		end++;
	end--;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	tmp = ft_strsub(s, start, end - start + 1);
	free(s);
	return (tmp);
}
