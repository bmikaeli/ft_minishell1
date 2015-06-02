/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:55:38 by bmikaeli          #+#    #+#             */
/*   Updated: 2015/02/04 15:09:30 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char			*ft_copy(char *buff_tmp, char **line)
{
	int				i;
	int				j;
	char			*tmp;

	i = 0;
	while (buff_tmp[i] != '\n')
		i++;
	j = i;
	while (buff_tmp[j] != '\0')
		j++;
	buff_tmp[i] = '\0';
	*line = ft_strdup(buff_tmp);
	buff_tmp[i] = '\n';
	i++;
	if (buff_tmp[i] != '\0')
	{
		tmp = buff_tmp;
		buff_tmp = ft_strsub(tmp, i, j);
		ft_strdel(&tmp);
		return (buff_tmp);
	}
	ft_strdel(&buff_tmp);
	return (buff_tmp);
}

static char			*ft_copy_buff_tmp(char *buff_tmp, char *buff)
{
	char			*tmp;

	if (buff_tmp == NULL)
		buff_tmp = ft_strdup(buff);
	else
	{
		tmp = buff_tmp;
		buff_tmp = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	return (buff_tmp);
}

int					get_next_line(int fd, char **line)
{
	static char		*buff_tmp;
	char			*buff;
	int				ret;

	if (buff_tmp != NULL && ft_strchr(buff_tmp, '\n') != NULL)
	{
		buff_tmp = ft_copy(buff_tmp, line);
		return (1);
	}
	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1 || fd == -1)
			return (-1);
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n') != NULL)
		{
			buff_tmp = ft_copy_buff_tmp(buff_tmp, buff);
			buff_tmp = ft_copy(buff_tmp, line);
			return (1);
		}
		buff_tmp = ft_copy_buff_tmp(buff_tmp, buff);
		buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	}
	return (0);
}
