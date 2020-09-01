/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:39:32 by rdonnor           #+#    #+#             */
/*   Updated: 2020/02/07 13:07:37 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_new_line(char **str, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[4096];
	t_gnl		gnl;

	ft_bzero(&gnl, 0);
	if (fd < 0 || line == NULL)
		return (-1);
	while ((gnl.ret = read(fd, gnl.buf, BUFF_SIZE)) > 0)
	{
		gnl.buf[gnl.ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(BUFF_SIZE);
		gnl.tmp = ft_strjoin(str[fd], gnl.buf);
		free(str[fd]);
		str[fd] = gnl.tmp;
		if (ft_strchr(gnl.buf, '\n'))
			break ;
	}
	if (gnl.ret < 0)
		return (-1);
	else if (gnl.ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_new_line(str, line, fd, gnl.ret));
}
