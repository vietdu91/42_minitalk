/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:03:47 by emtran            #+#    #+#             */
/*   Updated: 2021/08/30 14:29:37 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_strlen(char *str)
{
	int	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_factory(char *str, char j)
{
	int		len;
	char	*nstr;
	int		i;

	if (str == 0)
	{
		nstr = (char *)malloc(sizeof(char) * 2);
		if (nstr == 0)
			return (0);
		nstr[0] = j;
		nstr[1] = '\0';
		return (nstr);	
	}
	len = ft_strlen(str);
	nstr = (char *)malloc(sizeof(char) * (len + 2));
	if (nstr == 0)
		return (0);
	i = -1;
	while (str[++i])
		nstr[i] = str[i];
	nstr[len] = j;
	nstr[len + 1] = '\0';
	return (nstr);
}

int	main()
{
	char	*i = NULL;
	char	j = 'c';

	printf("Str : %s\n", str_factory(i, j));
}
