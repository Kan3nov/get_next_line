/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:57:58 by klafi             #+#    #+#             */
/*   Updated: 2025/12/29 15:59:20 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
//the following libraries will be omitted after testing 
#include <stdio.h>
#include <fcntl.c>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

typedef struct ll_node
{
	next	*ll_node;
	prev	*ll_node;
	char	str[2];
	int		len;
}	node;

#endif
