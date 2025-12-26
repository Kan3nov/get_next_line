/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:31:06 by klafi             #+#    #+#             */
/*   Updated: 2025/12/26 20:46:42 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (n > 0)
	{
		*(unsigned char *)(s + index) = c;
		index++;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}


size_t	ft_strlen(const char *s)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	index = 0;
	while (*(s + index) != 0)
	{
		counter++;
		index++;
	}
	return (counter);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	total;

	total = n * size;
	if (size == 0 || n == 0)
		ptr = malloc(0);
	else if (total / n != size)
		return (NULL);
	else
	{
		ptr = malloc(size * n);
		ft_bzero(ptr, size * n);
	}
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	index;

	index = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	if (dsize > ft_strlen(src) + 1)
		dsize = ft_strlen(src) + 1;
	while (index < dsize - 1)
	{
		*(dst + index) = *(src + index);
		index++;
	}
	*(dst + index) = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	length_src;
	size_t	length_dst;
	size_t	size;

	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (dsize > length_dst + length_src)
		dsize = length_dst + length_src + 1;
	size = dsize;
	while (*(dst) && dsize > 0)
	{
		dsize--;
		dst++;
	}
	ft_strlcpy(dst, src, dsize);
	if (size + length_src > length_dst + length_src)
		return (length_src + length_dst);
	return (size + length_src);
}

char	last_char(char *s)
{
	char 	c;

	c = *(s + ft_strlen(s) - 1);
	return (c);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*s;
	char	*temp;
	int		bytes;
	int		size;

	size = 1;
	temp = ft_calloc(2, 1);
	s = ft_calloc(2, 1);
	while (last_char(s) != '\n')
	{
		buff = malloc(BUFFER_SIZE);
		ft_strlcpy(temp, s, size);
		free(s);
		s = ft_calloc(1, ++size);
		ft_strlcpy(s, temp, size);
		free(temp);
		temp = ft_calloc(1, size);
		bytes = read(fd, buff, 1);
		ft_strlcat(s, buff, ft_strlen(s) + 2);
		free(buff);
		if (bytes == 0 && !(*s))
			return (NULL);
		else if(bytes == 0)
			break;
		else if (bytes == -1)
			return (NULL);
	}
	free(temp);
	return (s);
}
