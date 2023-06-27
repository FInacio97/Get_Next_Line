/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:12:52 by fda-estr          #+#    #+#             */
/*   Updated: 2023/06/27 19:16:05 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nlcheck(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*spliter(char *content)
{
	int		i;
	char	*prod;

	i = 0;
	while (content[i] != '\n' && content[i])
		i++;
	if (content[i] == '\n')
	{
		prod = malloc(i + 2);
		prod[i] = '\n';
		i++;
	}
	else
		prod = malloc(i + 1);
	prod[i] = '\0';
	i = 0;
	while (content[i] != '\n' && content[i])
	{
		prod[i] = content[i];
		i++;
	}
	if (nlcheck(content) == 0)
		free (content);
	return (prod);
}

char	*ft_strjoin(char *dest, char *src, char *tofree, int toread)
{
	char	*prod;
	int		i;
	int		j;
	int		size;

	size = 0;
	i = 0;
	while (dest[size])
		size++;
	while (src && src[i])
		i++;
	size += i;
	prod = malloc(size + 1);
	if (!prod)
		return (NULL);
	i = -1;
	j = -1;
	while (dest[++i])
		prod[i] = dest[i];
	while (src && src[++j] && j < toread)
		prod[i + j] = src[j];
	prod[i + j] = 0;
	if (tofree)
		free (tofree);
	return (prod);
}

char	*stringbuilder(char *content, char *save, int toread, int fd)
{
	char	*train;
	char	*temp;

	if (save)
	{
		temp = save;
		if (nlcheck(save) == 1)
		{
			while (*save != '\n')
				save++;
			save++;
		}
		train = ft_strjoin(save, content, temp, toread);
	}
	else
		train = ft_strjoin(content, "", NULL, toread);
	while (toread > 0 && nlcheck(train) == 0)
	{
		toread = read(fd, content, BUFFER_SIZE);
		if (toread > 0)
			train = ft_strjoin(train, content, train, toread);
	}
	return (train);
}
