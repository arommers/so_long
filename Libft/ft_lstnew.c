/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 09:05:37 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/02 16:30:03 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
**int		main(void)
**{
**	char	str[] = "all hail bulbasaur";
**
**	t_list	new;
**
**	new = ft_lstnew((void *)str);
**	printf("\n%s\n", new->content);
**}
*/