/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:23:47 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/26 15:57:52 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_read_text(int fd, char **remain)
{
	int		rcnt;
	int		idx;
	char	*buf;

	idx = 0;
	buf = (char *) ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (1)
	{
		rcnt = read(fd, buf + idx, BUFFER_SIZE);
		buf[BUFFER_SIZE + idx] = '\0';
		idx += BUFFER_SIZE;
		buf = ft_gnl_strdup(buf, BUFFER_SIZE);
		if (rcnt < BUFFER_SIZE || ft_check_newline(buf))
			break ;
	}
	(*remain) = ft_gnl_strjoin((*remain), buf);
	free(buf);
	return (rcnt);
}

char	*ft_get_answer(char **remain)
{
	char	*temp;
	char	*ans;
	int		idx_nl;
	int		idx_end;

	idx_nl = ft_gnl_strlen((*remain), '\n') + 1;
	idx_end = ft_gnl_strlen((*remain), '\0');
	ans = ft_substr((*remain), 0, idx_nl);
	temp = ft_substr((*remain), idx_nl, idx_end + 1);
	free(*remain);
	*remain = temp;
	return (ans);
}

char	*ft_return(int f, char **remain, char **ans)
{
	if (!*ans || **ans == '\0')
	{
		free(*ans);
		free(*remain);
		*remain = NULL;
		return (NULL);
	}
	if (f < 0)
	{
		if (*remain)
		{
			free(*remain);
			*remain = NULL;
		}
		if (*ans)
			free(*ans);
		return (NULL);
	}
	return (*ans);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*ans;
	int			f;

	f = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_check_newline(remain))
		f = ft_read_text(fd, &remain);
	ans = ft_get_answer(&remain);
	return (ft_return(f, &remain, &ans));
}
