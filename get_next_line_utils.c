/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:52:37 by klafi             #+#    #+#             */
/*   Updated: 2026/01/05 14:35:27 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(t_line line)
{
	int	idx;

	idx = 0;
	while (idx < line.len)
	{
		if (line.s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}
