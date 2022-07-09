/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:02:28 by imabid            #+#    #+#             */
/*   Updated: 2022/01/21 16:08:09 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*read_buffer_bonus(int fd, char *str)
{
	char	*buff;
	int		r;

	buff = malloc(1);
	if (!buff)
		return (NULL);
	r = 1;
	while (!ft_strchr1(str, '\n') && r)
	{
		r = read(fd, buff, 1);
		if (r == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin1(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_line_bonus(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_newrest_bonus(char *s)
{
	char	*new_rest;
	int		i;
	int		lens;
	int		j;

	j = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	lens = ft_strlen1(&s[i + 1]) + 1;
	new_rest = (char *)malloc(sizeof(char) * lens);
	if (!new_rest)
		return (NULL);
	i++;
	while (s[i])
		new_rest[j++] = s[i++];
	new_rest[j] = '\0';
	free (s);
	return (new_rest);
}

char	*get_next_line_bonus(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0)
		return (NULL);
	rest = read_buffer_bonus(fd, rest);
	if (!rest)
		return (NULL);
	line = get_line_bonus(rest);
	rest = get_newrest_bonus(rest);
	return (line);
}
