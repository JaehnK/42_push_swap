/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:02:38 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/12 13:46:39 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count_word(char const *s, char c)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = 1;
	if (!s[0])
		return (0);
	if (s[0] != c)
		cnt++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

char	*get_word(char const *s, char c)
{
	int		idx;
	char	*word;
	char	*ptr;

	idx = 0;
	ptr = (char *) s;
	while (*ptr != c && *ptr != '\0')
		ptr++;
	word = (char *) malloc(sizeof(char) * (ptr - s + 1));
	if (!word)
		return (NULL);
	while (s != ptr)
	{
		word[idx++] = *s++;
	}
	word[idx] = '\0';
	return (word);
}

char	**free_arr(char **words, int idx)
{
	while (idx > 0)
		free(words[--idx]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		idx_word;
	int		len_words;
	char	**words;

	if (!s)
		return (NULL);
	idx_word = 0;
	len_words = count_word(s, c);
	words = (char **) malloc(sizeof(char *) * (len_words + 1));
	if (!words)
		return (NULL);
	while (idx_word < len_words)
	{
		while (*s == c)
			s++;
		words[idx_word] = get_word(s, c);
		if (!words[idx_word])
			return (free_arr(words, idx_word));
		s += ft_strlen(words[idx_word]);
		idx_word++;
	}
	words[idx_word] = NULL;
	return (words);
}
