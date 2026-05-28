/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:07:49 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/03 11:24:48 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *next_line, char *buffer, int fd)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!next_line)
			next_line = ft_strdup("");
		tmp = ft_strjoin(next_line, buffer);
		if (!tmp)
			return (free(next_line), NULL);
		free(next_line);
		next_line = tmp;
		if (ft_strchr(buffer, '\n') > 0)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (free(next_line), NULL);
	return (next_line);
}

char	*ft_take_line(char	*next_line)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (next_line[i] != '\n' && next_line[i] != '\0')
		i++;
	if (next_line[i] == '\n')
		str = ft_substr(next_line, 0, i + 1);
	else if (next_line[i] == '\0')
		str = ft_strdup(next_line);
	if (!str)
		return (free(next_line), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line_rdy;
	char		*buffer;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	next_line = ft_read_line(next_line, buffer, fd);
	free(buffer);
	if (!next_line || ft_strlen(next_line) == 0)
		return (free(next_line), next_line = NULL, NULL);
	line_rdy = ft_take_line(next_line);
	if (!line_rdy)
		return (NULL);
	tmp = ft_strdup(&next_line[ft_strlen(line_rdy)]);
	if (!tmp)
		return (free(line_rdy), NULL);
	free(next_line);
	next_line = tmp;
	return (line_rdy);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*line;
// 	int	i;

// 	i = 1;
// 	line = "Hello";
// 	fd = open("doc.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error opening the file");
// 		return (0);
// 	}
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 			printf("appel numero %d : %s", i, line);
// 		i++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
