/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:57:48 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/14 18:32:05 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <stdlib.h>

char	*check_line2(char *str);
char	*get_buf(int fd, char *str);
char	*ft_strjoin_expand(char *s1, char const *s2);
char	*check_line(char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin_expand(char *s1, char const *s2);

#endif