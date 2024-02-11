/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:40 by aklein            #+#    #+#             */
/*   Updated: 2024/02/11 00:39:31 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line_bonus.h>

int	new_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*append_str_to_str(char *str, char *src, int len)
{
	char	*new_str;
	int		i;

	new_str = malloc(len + new_strlen(str) + 1);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str != NULL && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (*src && len--)
	{
		new_str[i] = *src;
		src++;
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == 0 && (unsigned char)c != 0)
		return (NULL);
	return ((char *)s);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	if ((!dst && !src) && len != 0)
		return (NULL);
	temp = dst;
	if (dst <= src)
		while (len--)
			*temp++ = *(char *)src++;
	else
	{
		temp += len;
		src += len;
		while (len--)
			*(--temp) = *(char *)(--src);
	}
	return (dst);
}
