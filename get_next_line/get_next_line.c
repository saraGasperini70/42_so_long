/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:23:12 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/10 15:44:18 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*function_name(int fd, char *buf, char *bkp)
{
	int		readed;
	char	*temp;

	readed = 1;
	while (readed != '\0')
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (0);
		else if (readed == 0)
			break ;
		buf[readed] = '\0';
		if (!bkp)
			bkp = ft_strdup("");
		temp = bkp;
		bkp = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (bkp);
}

static char	*extract(char *line)
{
	size_t	i;
	char	*bkp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	bkp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*bkp == '\0')
	{
		free(bkp);
		bkp = NULL;
	}
	line[i + 1] = '\0';
	return (bkp);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*bkp[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = function_name(fd, buf, bkp[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	bkp[fd] = extract(line);
	return (line);
}
