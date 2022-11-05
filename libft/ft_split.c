/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:42:03 by aaugu             #+#    #+#             */
/*   Updated: 2022/11/05 15:37:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c);
char	*ft_strndup(const char *s, size_t n);
char	**ft_freeall(char **list);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	save;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!strs)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		save = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		strs[i] = ft_substr(s, save, j - save);
		if (strs[i++] == 0)
			return (ft_freeall(strs));
	}
	strs[i] = NULL;
	return (strs);
}

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != '\0' && s[i + 1] != c) || \
			(i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_freeall(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

// int	main(void)
// {
// 	char const	*s1 = "bliiiablooableeeea";
// 	char const	*s2 = "bablablo";
//   	char const	*s3 = "abablablo";
// 	char        c = 'a';

//   printf("%d\n", ft_split(s1, c));
//   printf("%d\n", ft_split(s2, c));
//   printf("%d\n", ft_split(s3, c));
// 	return (0);
// }
