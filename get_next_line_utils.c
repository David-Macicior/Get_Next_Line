/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:24:15 by dmacicio          #+#    #+#             */
/*   Updated: 2021/11/17 22:23:47 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		i;
	int		x;

	if (NULL == s1 || NULL == s2)
		return ((char *) NULL);
	out = malloc(sizeof(char) * (lng(s1) + lng(s2) + 1));
	if (!out)
		return ((char *) NULL);
	i = 0;
	while ('\0' != s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	x = 0;
	while ('\0' != s2[x])
	{
		out[i] = s2[x];
		i++;
		x++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_strdup(const char *s1)
{
	char	*out;
	int		s1len;

	s1len = lng(s1);
	out = malloc(sizeof(char) * (s1len + 1));
	if (!out)
		return ((char *) NULL);
	ft_strlcpy(out, s1, s1len + 1);
	return ((char *) out);
}

int	lng(const char *str)
{
	int	str_length;

	str_length = 0;
	while (str[str_length])
		str_length++;
	return (str_length);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	cpyindex;
	size_t	srcsizeindex;

	srcsizeindex = 0;
	cpyindex = 0;
	while ('\0' != src[srcsizeindex])
	{
		if (size > 0 && cpyindex < (size - 1))
		{
			dest[cpyindex] = src[cpyindex];
			cpyindex++;
		}
		srcsizeindex++;
	}
	if (size > 0)
		dest[cpyindex] = '\0';
	return (srcsizeindex);
}

char	*join_o_h(t_aux *v, char *h)
{
	if (!v->o)
	{
		if (h)
			v->o = h;
		h = NULL;
	}
	else
	{
		v->aux1 = v->o;
		if (hnl(v->o, '\n') >= 0)
			v->aux = ft_substr(v->o, 0, (hnl(v->o, '\n') + 1));
		else
			v->aux = v->o;
		v->o = ft_strjoin(h, v->aux);
		if (hnl(v->o, '\n') >= 0)
			free(v->aux);
		v->aux = h;
		if (hnl(v->aux1, '\n') >= 0 && lng(v->aux1) - hnl(v->aux1, '\n') > 1)
			h = ft_substr(v->aux1, (hnl(v->aux1, '\n') + 1), lng(v->aux1));
		else
			h = NULL;
		free(v->aux1);
		free(v->aux);
	}
	return (h);
}
