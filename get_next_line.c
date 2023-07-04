/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:12:55 by fda-estr          #+#    #+#             */
/*   Updated: 2023/07/04 18:58:30 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_clean_franciscos_zalupa(char *zalupa)
{
	int	i;

	i = -1;
	while (zalupa[++i])
		zalupa[i] = 0;
	return (NULL); 
}


char	*get_next_line(int fd)
{
	static char	content[BUFFER_SIZE + 1];
	char		*save;
	int			toread;

	content[BUFFER_SIZE] = 0;
	toread = 0;
	if (fd < 0 || !BUFFER_SIZE || fd > FOPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_clean_franciscos_zalupa(content));	
	if (!*content) /* e se dentro do content, antes da primeira call do gnl, existir lixo na memoria?*/ 
		toread = read(fd, content, BUFFER_SIZE);
	else
	{
		while (content[toread])
			toread++;
	}
	if (toread < 0)
		return (NULL);
	if (toread < BUFFER_SIZE && toread > 0)
		content[toread] = 0;
	if (!*content)
		return (NULL);
	save = stringbuilder(content, toread, fd);
	// saver(content, save);
	return (spliter(save, content));
}

// int	main()
// {
// 	int	fd;
// 	char *str;
// 	printf("=Resut=\n");
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("ERRO\n");
// 	str =  get_next_line(fd);
// 	printf("====str====\n%s\n", str);
// 	free(str);
// 	str =  get_next_line(fd);
// 	printf("====str====\n%s\n", str);
// 	free(str);
// 	str =  get_next_line(fd);
// 	printf("====str====\n%s\n", str);
// 	free(str);
// 	str =  get_next_line(fd);
// 	printf("====str====\n%s\n", str);
// 	if (str == NULL)
// 		printf("\nNULL\n");
// 	free(str);

// 	// str =  get_next_line(fd);
// 	// printf("====str====\n%s\n", str);
// 	// while (1)
// 	// {
// 	// 	str =  get_next_line(fd);
// 	// 	if (!str)
// 	// 		break ;
// 	// 	printf("%s", str);
// 	// 	free(str);
// 	// }
// 	// free (str);
// 	// str =  get_next_line(fd);
// 	// if (!str)
// 	// 	printf("NULL\n");
// 	// else
// 	// 	printf("Not NULL");
// 	// printf("======");
// }

	// int main()
	// {
	// 	int fd;
	// 	char *zalupa;

	// 	fd = open("test.txt", O_RDONLY);
	// 	zalupa = get_next_line(fd);
	// 	printf("%s", zalupa);
	// 	free (zalupa);
	// }