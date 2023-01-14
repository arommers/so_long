/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 11:21:43 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/04 09:18:26 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*placeholder;

	if (lst || new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			placeholder = *lst;
			while (placeholder->next != NULL)
				placeholder = placeholder->next;
			placeholder->next = new;
		}
	}
}
