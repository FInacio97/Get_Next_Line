/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:12:55 by fda-estr          #+#    #+#             */
/*   Updated: 2023/06/27 19:33:05 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		content[BUFFER_SIZE + 1];
	static char	*save;
	int			toread;

	content[BUFFER_SIZE] = 0;
	if (fd < 0 || !BUFFER_SIZE || fd > FOPEN_MAX)
		return (NULL);
	if (!save)
		save = NULL;
	toread = read(fd, content, BUFFER_SIZE);
	if (toread <= 0)
		return (NULL);
	save = stringbuilder(content, save, toread, fd);
	return (spliter(save));
}

int	main()
{
	int	fd;
	char *str;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("ERRO\n");
	
	str = get_next_line(fd);
	if (str == NULL)
		printf("NULL\n");
	else
		printf("%s", str);
	free(str);
	str = get_next_line(fd);
	if (str == NULL)
		printf("NULL\n");
	else
		printf("%s", str);
	free(str);
	str = get_next_line(fd);
	if (str == NULL)
		printf("NULL\n");
	else
		printf("%s", str);
	free(str);
}