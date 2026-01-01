/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:02:27 by klafi             #+#    #+#             */
/*   Updated: 2026/01/01 12:33:15 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *str_rev(int idx, node **list, int length)
{
	char 	*s;
	node	**temp;

	temp = list;
	s = ft_calloc(length + 1);
	s[length] = 0;
	while (length--)
	{
		s[length] = ((*list) -> str)[idx];
		if (idx == 0)
		{
			*temp = (*temp) -> prev;
			idx = BUFFER_SIZE;
		}
		idx--;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static node **list = NULL;
	static int	idx = 0;
	int			length;

	length = 0;
	if (!list)
		list = new_lst(fd);
	if (!list)
		return (NULL);
	while (idx < (*list) -> len)
	{
		if ((*list) -> len == 0)
			break ;
		length++;
		if (((*list) -> str)[idx] == '\n')
			break ;
		idx++;
		if (idx == BUFFER_SIZE)
		{
			*list = lst_add_back(list, fd);
			if (!*list)
				return (NULL);
			idx = 0;
		}
	}
	if ((*list) -> len == 0 && length == 0)
		return (NULL);
	return (str_rev(idx, list, length));
}
