/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:13:44 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 11:39:25 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_set(s1[start], set))
		start++;
	while (end >= 0 && ft_set(s1[end], set))
	{
		if (end == 0)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	dest = (char *)malloc((end - start + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy (dest, (s1 + start), end - start + 2);
	return (dest);
}
/*
int	main(void)
{
	char	*str;

	str = ft_strtrim(NULL, "123569abcd");
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
