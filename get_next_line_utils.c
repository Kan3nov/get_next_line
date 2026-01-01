/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:08:00 by klafi             #+#    #+#             */
/*   Updated: 2025/12/29 15:59:58 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

node	*lst_new(char *s,int len)
{
	node	*nd;

	nd = malloc (sizeof (node));
	nd -> next = NULL;
	nd -> prev = NULL;
	nd -> str = s;
	nd -> len = len;
	return nd;
}

void	lst_add_back(node **list, node *nd)
{
	node	**temp;

	temp = list;
	while ((*temp) -> next)
		(*temp) = *(temp) -> next;
	(*temp) -> next = nd;
}


