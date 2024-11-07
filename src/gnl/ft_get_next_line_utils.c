/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:16:13 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:16:16 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	contador;

	contador = 0;
	if (!s)
		return (0);
	while (s[contador])
		contador ++;
	return (contador);
}

char	*ft_gnl_strjoin(char	*s1, char	*s2)
{
	size_t	n;
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	n = ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1;
	p = malloc(n * sizeof(char));
	if (!p)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0' && s1 != NULL)
		{
			p[i] = s1[i];
			i ++;
		}
	}
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[n - 1] = '\0';
	free(s1);
	free(s2);
	return (p);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	while (s[pos] != '\0' && s[pos] != (char)c)
		pos ++;
	if (!s || s[pos] == '\0')
		return (NULL);
	return ((char *)(s + pos));
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((start + len) <= ft_gnl_strlen(s))
		p = malloc((len + 1) * sizeof(char));
	else if (ft_gnl_strlen(s) < start)
		p = malloc(sizeof(char));
	else
		p = malloc((ft_gnl_strlen(s) - start + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (start < ft_gnl_strlen(s) && i < len)
	{
		p[i] = s[start];
		start ++;
		i ++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_gnl_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc((ft_gnl_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i ++;
	}
	p[i] = '\0';
	return (p);
}
