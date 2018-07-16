/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:43:19 by bgres             #+#    #+#             */
/*   Updated: 2017/11/04 19:46:20 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		kw(char const *s, char d)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (s[i] == d && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != d && s[i] != '\0')
			i++;
		n++;
		while (s[i] == d && s[i] != '\0')
			i++;
	}
	return (n);
}

static void		*fill(char const *s, char *a, int n)
{
	int		i;

	i = 0;
	while (i <= n)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

static int		check(int *n, int *j, int *i, char const *s)
{
	*n = 0;
	*j = 0;
	*i = 0;
	if (!s)
		return (1);
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**av;
	int		j;
	int		i;
	int		n;

	if (check(&n, &i, &j, s))
		return (NULL);
	av = (char **)malloc(sizeof(char *) * kw(s, c) + 1);
	if (!av)
		return (NULL);
	while (i < kw(s, c))
	{
		while (s[j++] == c)
			;
		while (s[j] != c && s[j] != '\0')
		{
			j++;
			n++;
		}
		av[i] = (char *)malloc(sizeof(char) * (n + 2));
		fill(&s[j - n - 1], av[i++], n);
		n = 0;
	}
	av[i] = NULL;
	return (av);
}
