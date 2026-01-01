/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:57:58 by klafi             #+#    #+#             */
/*   Updated: 2026/01/01 17:32:47 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
//the following libraries will be omitted after testing 
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

typedef struct ll_node
{
	struct ll_node	*next;
	struct ll_node	*prev;
	char			*str;
	int				len;
}	node;
node	*lst_new(int fd);
node	*lst_add_back(node *list, int fd);
void	*ft_calloc(size_t n, size_t size);
char	*get_next_line(int fd);

#endif
