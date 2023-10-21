/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:34:12 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/29 13:05:57 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*space_crop_tm(char *s)
{
	int	i;

	if (!(s - 1))
		return (NULL);
	i = 0;
	while (ft_isspace(*s))
		s++;
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i--]))
		s[i + 1] = '\0';
	return (s);
}

void	big_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	mixed_free(char **s1, char *s2)
{
	free(s2);
	big_free(s1);
}

void	double_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*is_space_n(char *s, int n)
{
	char	*res;

	res = ft_substr(s, n, ft_strlen(s) - n);
	free(s);
	return (res);
}
