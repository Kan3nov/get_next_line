/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:15:05 by klafi             #+#    #+#             */
/*   Updated: 2026/01/05 15:07:01 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	strjoin(t_line line, char *buf, int bytes)
{
	char		*new;
	int			idx;
	int			old_bytes;

	new = malloc(line.len + bytes);
	old_bytes = bytes;
	idx = -1;
	while (++idx < line.len)
		new[idx] = line.s[idx];
	while (bytes-- > 0)
	{
		new[idx] = buf[idx - line.len];
		idx++;
	}
	free(buf);
	if (line.len != 0)
		free (line.s);
	if (line.len == 0 && old_bytes == 0)
		free(new);
	line.s = new;
	line.len = old_bytes + line.len;
	return (line);
}

char	*substr(t_line line, int idx2)
{
	char	*new;
	int		idx1;

	new = malloc(idx2 + 2);
	idx1 = 0;
	while (idx1 < idx2 + 1)
	{
		new[idx1] = line.s[idx1];
		idx1++;
	}
	new[idx1] = 0;
	return (new);
}

t_line	trim(t_line line, int idx2)
{
	char	*new;
	int		idx1;
	int		new_len;

	new_len = line.len - idx2 - 1;
	if (new_len == 0)
		new = "";
	else
		new = malloc (new_len + 1);
	idx1 = 0;
	while (idx1 < new_len)
		new[idx1++] = line.s[++idx2];
	free(line.s);
	line.s = new;
	line.len = new_len;
	return (line);
}

char	*gnl(int fd, char *buf, int idx, int bytes)
{
	static t_line	line = {"", 0};
	char			*new;

	idx = find_nl(line);
	while (idx < 0)
	{
		buf = malloc(BUFFER_SIZE);
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), NULL);
		line = strjoin(line, buf, bytes);
		idx = find_nl(line);
		if (bytes < BUFFER_SIZE && idx < 0)
		{
			idx = line.len - 1;
			break ;
		}
	}
	if (bytes == 0 && line.len <= 0)
		return (NULL);
	new = substr(line, idx);
	line = trim(line, idx);
	return (new);
}

char	*get_next_line(int fd)
{
	return (gnl(fd, "", 0, 0));
}
