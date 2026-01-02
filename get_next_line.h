/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:57:58 by klafi             #+#    #+#             */
/*   Updated: 2026/01/02 07:52:20 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
//the following libraries will be omitted after testing 
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct ll_node
{
	struct ll_node	*next;
	struct ll_node	*prev;
	char			*str;
	int				len;
}	t_node;
t_node	*lst_new(int fd);
t_node	*lst_add_back(t_node *list, int fd);
void	*ft_calloc(size_t n, size_t size);
char	*get_next_line(int fd);

#endif
