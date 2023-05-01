/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:24:18 by dmacicio          #+#    #+#             */
/*   Updated: 2021/11/23 17:36:57 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_aux		v;
	static char	*h = NULL;

	v.o = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (v.o);
	if (h && hnl(h, '\n') >= 0 && hnl(h, '\n') + 1 != lng(h))
	{
		v.aux = h;
		v.o = ft_substr(h, 0, (hnl(h, '\n') + 1));
		h = ft_substr(h, (hnl(h, '\n') + 1), lng(v.aux));
		free(v.aux);
		return (v.o);
	}
	v.o = ft_readtillnewline(fd);
	if (NULL != h)
		h = join_o_h(&v, h);
	else
		h = substr_o_h(&v);
	return (v.o);
}

char	*substr_o_h(t_aux *v)
{
	char	*h;

	h = NULL;
	if (v->o && (hnl(v->o, '\n') >= 0))
	{
		if (hnl(v->o, '\n') + 1 != lng(v->o) && lng(v->o) != 1)
		{
			v->aux = v->o;
			h = ft_substr(v->o, (hnl(v->o, '\n') + 1), lng(v->o));
			v->o = ft_substr(v->o, 0, (hnl(v->o, '\n') + 1));
			free(v->aux);
		}
	}	
	return (h);
}

char	*ft_readtillnewline(int fd)
{
	t_aux	aux;

	aux.o = NULL;
	aux.readlen = 1;
	aux.buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (aux.readlen > 0 && (NULL == aux.o || hnl(aux.o, '\n') < 0))
	{
		aux.readlen = read(fd, aux.buffer, BUFFER_SIZE);
		if (aux.readlen > 0)
		{
			aux.buffer[aux.readlen] = '\0';
			if (NULL == aux.o)
				aux.o = ft_strdup(aux.buffer);
			else
			{
				aux.aux = aux.o;
				aux.o = ft_strjoin(aux.o, aux.buffer);
				free(aux.aux);
			}
		}
		else if (aux.readlen == -1)
			aux.o = NULL;
	}
	free(aux.buffer);
	return (aux.o);
}

int	hnl(const char *str, int c)
{
	char	*aux;
	int		index;

	index = 0;
	aux = (char *)str;
	while (aux[index])
	{
		if (aux[index] == (char)c)
			return (index);
		index++;
	}
	if (aux[index] == (char)c)
		return (index);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*out;
	size_t			index;
	unsigned int	slen;

	if (!s || start >= (unsigned int)lng(s))
	{
		out = malloc(sizeof(char));
		if (!out)
			return ((char *) NULL);
		out[0] = '\0';
		return (out);
	}
	slen = (unsigned int)lng(s) - start;
	if (slen < len)
		len = (size_t)slen;
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return ((char *) NULL);
	index = -1;
	while (++index < len)
		out[index] = s[(size_t)start + index];
	out[index] = '\0';
	return (out);
}
