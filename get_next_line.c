/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:15:05 by klafi             #+#    #+#             */
/*   Updated: 2026/01/06 16:03:13 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(t_buf *buf)
{
	int	idx;

	idx = buf->idx;
	while (idx < buf->len)
	{
		if (buf->s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*strjoin(char *line, t_buf *buf)
{
	char	*new;
	int		idx;
	int		len;
	int		nl;

	len = ft_strlen(line);
	nl = find_nl(buf);
	if (nl < 0 && buf->len >= 0)
		nl = buf->len - 1;
	new = malloc(len + (nl - buf->idx + 1) + 1);
	idx = -1;
	while (++idx < len)
		new[idx] = line[idx];
	while (buf->idx <= nl)
	{
		new[idx++] = buf->s[buf->idx];
		buf->idx++;
	}
	new[idx] = 0;
	free(line);
	return (new);
}

int	in(char *s, char c)
{
	int	idx;

	idx = 0;
	while (s[idx])
		if (s[idx++] == c)
			return (idx);
	return (-1);
}

char	*get_next_line(int fd)
{
	static t_buf	buf = {"", 0, 0};
	char			*line;

	line = malloc(1);
	line[0] = 0;
	while (in(line, '\n') == -1)
	{
		if (buf.idx == buf.len)
		{
			buf.len = read(fd, buf.s, BUFFER_SIZE);
			buf.idx = 0;
		}
		line = strjoin(line, &buf);
		if (!buf.len)
			break ;
		else if (buf.len < 0)
			return (free(line), NULL);
	}
	if (!buf.len && !ft_strlen(line))
		return (free(line), NULL);
	return (line);
}
