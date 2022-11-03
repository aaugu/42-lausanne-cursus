/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:42:35 by aaugu             #+#    #+#             */
/*   Updated: 2022/11/02 14:03:42 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_set_start(char const *s1, char const *set);
int	count_set_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	start = count_set_start(s1, set);
	end = count_set_end(s1, set);
	if (ft_strlen(s1) - end - start > 0)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s1) - end - start + 1));
	else
		return (ft_strdup(""));
	if (!str)
		return (0);
	i = 0;
	while (start - 1 < end - 1)
	{
		str[i] = s1[start - 1];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int	count_set_start(char const *s1, char const *set);

int	count_set_end(char const *s1, char const *set);
