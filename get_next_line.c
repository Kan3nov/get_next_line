/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:14:11 by klafi             #+#    #+#             */
/*   Updated: 2025/12/29 16:01:48 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static node	**list = &lst_new("", -1);
	char		*buff;
	
	buff = ft_calloc (1, BUFFER_SIZE);
	*list -> len = read(1, buff, BUFFER_SIZE);
	*list -> str = buff;
}
