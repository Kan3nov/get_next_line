/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:08:00 by klafi             #+#    #+#             */
/*   Updated: 2026/01/01 16:50:45 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

node	*lst_new(int fd)
{
	node	*nd;
	char	*buff;

	nd = malloc(sizeof (node));
	buff = ft_calloc(1, BUFFER_SIZE);
	if (!nd || !buff)
		return (NULL);
	nd -> next = NULL;
	nd -> prev = NULL;
	nd -> len = read(fd, buff, BUFFER_SIZE);
	if (nd -> len == -1)
		return (NULL);
	nd -> str = buff;
	return (nd);
}

node	*lst_add_back(node *list, int fd)
{
	node	*temp;
	node	*new;

	temp = list;
	new = lst_new(fd);
	if (!new)
		return (NULL);
	while ((temp) -> next)
		(temp) = (temp) -> next;
	new -> prev = temp;
	(temp) -> next = new;
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
