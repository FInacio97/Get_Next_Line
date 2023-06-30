/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:12:52 by fda-estr          #+#    #+#             */
/*   Updated: 2023/06/28 21:15:33 by fda-estr         ###   ########.fr       */
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

int endcheck(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (str[j] && str[j] != '\n')
		j++;
	if (str[j] == '\n')
		j++;
	if (i == j)
		return (1);
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
	// printf("\n=========Spliter check===========\n");
	if (endcheck(content) == 1)
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
	while (dest && dest[size])
		size++;
	while (src && src[i])
		i++;
	size += i;
	prod = malloc(size + 1);
	if (!prod)
		return (NULL);
	i = -1;
	j = -1;
	while (dest && dest[++i])
		prod[i] = dest[i];
	while (src && src[++j] && j < toread)
		prod[i + j] = src[j];
	prod[i + j] = 0;
		// printf("\n=========check===========\n");
		(void) tofree;
	if (tofree)
		free (tofree);
	return (prod);
}

char	*stringbuilder(char *content, char *save, int toread, int fd)
{
	char	*train;
	char	*temp;

	// printf("\n==Entrou no strbuilder==\n");
	if (save)
	{
		temp = save;
		if (nlcheck(save) == 1)
		{
			while (*save != '\n' && *save)
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
	// printf("=train=\n%s=", train);
	return (train);
}
