/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:30:18 by dmacicio          #+#    #+#             */
/*   Updated: 2023/05/01 18:27:12 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	static int	fd;
	char		*str;
	char		*error;
	const char	*fileName;

	str = NULL;
	fileName = "/Users/dmacicio/Desktop/Cursus/Testers/GetNextLine/gnlTester/files/multiple_line_with_nl";
	//fileName = "/Users/dmacicio/Desktop/Cursus/03_GetNextLine/fileToRead.txt";
	error = "Error al leer el fichero \"fileToRead.txt\"\n.";
	fd = open(fileName, O_RDONLY);
	if (-1 == fd)
		write(1, error, 46);
	else
	{
		str = get_next_line(fd);
		if (NULL != str)
			printf("%s", str);
			//write(1, str, ft_strlen(str));
		free(str);
		while (str)
		{
			str = get_next_line(fd);
			printf("%s", str);
			free(str);
			//if (NULL != str)
				//write(1, str, ft_strlen(str));
		}
	}
	system("leaks a.out");
	close(fd);
}
