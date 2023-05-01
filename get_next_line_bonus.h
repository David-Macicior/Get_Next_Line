/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:24:07 by dmacicio          #+#    #+#             */
/*   Updated: 2023/05/01 18:26:47 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h> 
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct aux
{
	char		*buffer;
	int			readlen;
	char		*o;
	char		*aux;
	char		*aux1;
}t_aux;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		lng(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		hnl(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_readtillnewline(int fd);
char	*substr_o_h(t_aux *v);
char	*join_o_h(t_aux *v, char *h);

#endif