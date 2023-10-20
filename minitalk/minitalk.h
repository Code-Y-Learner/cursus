/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:34:02 by seungjyu          #+#    #+#             */
/*   Updated: 2023/10/19 17:39:56 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		check_format(const char *str, va_list *ap);
int		ft_swrite(char *str);
int		ft_dwrite(int c);
size_t	ft_cwrite(int c);

int		ft_atoi(const char *str);
int		ft_check(int pm, unsigned long long num);

void	kill_checker(pid_t pid, int sig);
void	send_bit(unsigned char c, pid_t pid);
void	get_pid(void);

#endif
