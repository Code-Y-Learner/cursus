/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:38:00 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/17 15:50:14 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*check_line2(char *str);
char	*get_buf(int fd, char *str);
char	*ft_strjoin_expand(char *s1, char const *s2);
char	*check_line(char *str);
char	*get_next_line(int fd);

char	*check_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	line = ft_memmove(line, str, i);
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*check_line2(char *str)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	tmp = (char *)malloc(len - i + 1);
	if (!tmp)
		return (0);
	if (str[i] == '\n')
		i++;
	ft_memmove(tmp, &str[i], len - i + 1);
	tmp[len - i + 1] = '\0';
	if (str)
		free(str);
	return (tmp);
}

char	*ft_strjoin_expand(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (0);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*get_buf(int fd, char *str)
{
	int		read_size;
	char	buf[BUFFER_SIZE + 1];

	read_size = 1;
	while (read_size != 0 && !ft_strchr(buf, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		buf[read_size] = '\0';
		str = ft_strjoin_expand(str, buf);
	}
	if (read_size == -1)
		return (0);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = get_buf(fd, str);
	if (!str)
		return (0);
	line = check_line(str);
	str = check_line2(str);
	return (line);
}
