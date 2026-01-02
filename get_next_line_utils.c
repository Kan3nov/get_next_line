/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:08:00 by klafi             #+#    #+#             */
/*   Updated: 2026/01/02 08:37:59 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*lst_new(int fd)
{
	t_node	*nd;
	char	*buff;

	nd = malloc(sizeof (t_node));
	buff = ft_calloc(1, BUFFER_SIZE);
	if (!nd || !buff)
		return (NULL);
	nd -> next = NULL;
	nd -> prev = NULL;
	nd -> len = read(fd, buff, BUFFER_SIZE);
	if (nd -> len == -1)
	{
		free(buff);
		free (nd);
		return (NULL);
	}
	nd -> str = buff;
	return (nd);
}

t_node	*lst_add_back(t_node *list, int fd)
{
	t_node	*temp;
	t_node	*new;

	temp = list;
	new = lst_new(fd);
	if (!new)
		return (NULL);
	while ((temp)-> next)
		(temp) = (temp)-> next;
	new -> prev = temp;
	(temp)-> next = new;
	return (new);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	total;
	size_t	idx;

	total = size * n;
	if (size == 0 || n == 0)
		ptr = malloc(0);
	else if (total / size != n)
		return (NULL);
	else
	{
		ptr = malloc(size * n);
		if (!ptr)
			return (NULL);
		idx = 0;
		while (total > 0)
		{
			*(unsigned char *)(ptr + idx) = 0;
			idx++;
			total--;
		}
	}
	return (ptr);
}
