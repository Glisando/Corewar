/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:04:12 by bgres             #+#    #+#             */
/*   Updated: 2017/12/02 16:07:22 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE  100000

typedef struct		s_nada
{
	int				fd;
	char			*buf;
	char			*tmp;
	int				flag;

	struct s_nada	*next;
}					t_nada;

int					get_next_line(const int fd, char **line);
#endif
