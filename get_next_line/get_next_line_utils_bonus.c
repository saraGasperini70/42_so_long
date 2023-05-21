/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:02:10 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/10 15:02:30 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	j = 0;
	i = 0;
	str = malloc((ft_strlen(s1)+ft_strlen(s2)+1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*t;
	size_t	i;

	t = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	i = 0;
	if (t == NULL)
		return (NULL);
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char			*c;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = (unsigned int)len;
	if (ft_strlen((char *)s) <= len)
		c = (char *) malloc(ft_strlen((char *)s) + 1);
	else
		c = (char *) malloc(j + 1);
	if (!c)
		return (NULL);
	if (!((unsigned int) ft_strlen((char *)s) < start))
	{
		while (s[i] != '\0' && i < j)
		{
			c[i] = s[start];
			i++;
			start++;
		}
	}
	c[i] = '\0';
	return (c);
}

