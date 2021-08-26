/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:03:47 by emtran            #+#    #+#             */
/*   Updated: 2021/08/23 15:09:52 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
   int		i;
   int		bitshift;
   char	word;

   if (argc != 2)
   	return (1);
   word = argv[1][0];
   bitshift = -1;
   printf("%c[%d]: ", word, word);
   while (++bitshift < 8)
   {
   	if (word & 0x80 >> bitshift)
   		printf("1");
   	else
   		printf("0");
   }
   printf("\n");
   return (0);
}
