/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:02:27 by klafi             #+#    #+#             */
/*   Updated: 2026/01/02 08:28:30 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_rev(int idx, t_node *list, int length)
{
	char	*s;
	t_node	*temp;

	temp = list;
	if (idx < 0 && temp -> prev)
	{
		temp = (temp)-> prev;
		idx = BUFFER_SIZE - 1;
	}
	else if (idx < 0)
		idx = 0;
	s = ft_calloc(1, length + 1);
	s[length] = 0;
	while (length--)
	{
		s[length] = ((temp)-> str)[idx];
		if (idx-- == 0)
		{
			temp = (temp)-> prev;
			idx = BUFFER_SIZE - 1;
		}
	}
	return (s);
}

int	get_length(int *idx, t_node **list, int length, int fd)
{
	if ((*idx) == BUFFER_SIZE)
	{
		*list = lst_add_back(*list, fd);
		if (!*list)
			return (-1);
		*idx = 0;
	}
	while (*idx < (*list)-> len)
	{
		if ((*list)-> len == 0)
			break ;
		length++;
		if (((*list)-> str)[(*idx)++] == '\n')
			break ;
		if (*idx == BUFFER_SIZE)
		{
			*list = lst_add_back(*list, fd);
			if (!*list)
				return (-1);
			*idx = 0;
		}
	}
	return (length);
}

char	*get_next_line(int fd)
{
	static t_node	**list = NULL;
	static t_node	*head = NULL;
	static int		idx;
	int				length;

	if (!list)
		head = lst_new(fd);
	if (!head)
		return (NULL);
	list = &head;
	length = get_length(&idx, list, 0, fd);
	if (length == -1)
		return (NULL);
	if ((*list)-> len == idx && length == 0)
		return (NULL);
	return (str_rev(idx - 1, *list, length));
}
