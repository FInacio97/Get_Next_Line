/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:12:58 by fda-estr          #+#    #+#             */
/*   Updated: 2023/06/30 18:16:05 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
int		nlcheck(char *str);
int 	endcheck(char *str);
char	*spliter(char *content);
char	*ft_strjoin(char *dest, char *src, char *tofree, int toread);
char	*stringbuilder(char *content, char *save, int todread, int fd);

#endif