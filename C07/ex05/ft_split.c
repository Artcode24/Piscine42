/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:36:25 by arthur            #+#    #+#             */
/*   Updated: 2025/01/16 15:02:26 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ischarset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_countwords(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!ft_ischarset(str[i], charset) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (ft_ischarset(str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, int start, int end)
{
	char	*dest;
	int		i;

	dest = malloc((end - start) + 2);
	i = 0;
	while (start <= end)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		start;
	char	**arr;
	
	i = 0;
	j = 0;
	start = 0;
	arr = malloc((ft_countwords(str, charset) + 1) * sizeof(char *));
	while (str[i])
	{
		if (ft_ischarset(str[i], charset) && i > start)
		{
			if (i > start)
				arr[j++] = ft_strdup(str, start, i - 1);
			start = i + 1;
		}
		else if (ft_ischarset(str[i], charset))
			start = i + 1;
		i++;
	}
	if (i > start && !ft_ischarset(str[i - 1], charset))
		arr[j++] = ft_strdup(str, start, i - 1);
	arr[j] = NULL;
	return (arr);
}

/* 
#include <stdio.h>
int	main(void)
{
	char *str = "Hello..comment,ca;va,";
	char *charset = ".,;";
	
	char **result = ft_split(str, charset);
	
	for (int i = 0; result[i] != NULL; i++)
		printf("%s\n", result[i]);
} */