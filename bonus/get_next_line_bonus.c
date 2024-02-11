/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2024/02/11 00:39:10 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line_bonus.h>

static char	*free_and_exit(char *next_line)
{
	if (next_line && *next_line)
		return (next_line);
	if (next_line)
		free(next_line);
	return (NULL);
}

static int	bad_params(int fd, char *buffer)
{
	if (fd < 0 || read(fd, 0, 0) < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
	{
		buffer[0] = '\0';
		return (1);
	}
	return (0);
}

static char	*build_line(char *next_line, char *buffer, char *nl_ptr)
{
	int	bytes_to_move;

	bytes_to_move = 0;
	if (!*nl_ptr)
	{
		next_line = append_str_to_str(next_line, buffer, nl_ptr - buffer);
		buffer[0] = '\0';
	}
	else
	{
		next_line = append_str_to_str(next_line, buffer, nl_ptr - buffer + 1);
		bytes_to_move = new_strlen(nl_ptr + 1) + 1;
	}
	ft_memmove(buffer, nl_ptr + 1, bytes_to_move);
	if (!next_line)
		return (free_and_exit(next_line));
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			read_len;
	char		*next_line;
	char		*nl_ptr;

	next_line = NULL;
	if (bad_params(fd, buf))
		return (NULL);
	while (42)
	{
		if (buf[0] == '\0')
		{
			read_len = read(fd, buf, BUFFER_SIZE);
			if (read_len <= 0)
				return (free_and_exit(next_line));
			buf[read_len] = '\0';
		}
		nl_ptr = ft_strchr(buf, '\n');
		if (nl_ptr)
			return (build_line(next_line, buf, nl_ptr));
		next_line = build_line(next_line, buf, ft_strchr(buf, '\0'));
	}
}