/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <bokwuful@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:02:45 by macbookpro1       #+#    #+#             */
/*   Updated: 2024/10/07 12:36:14 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

/*
int		main(void)
{
	char	str[] = "test";

	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*elem5;
	t_list	*elem6;
	t_list	*res;

	if(!(elem1 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem2 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem3 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem4 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem5 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem6 = malloc(sizeof(t_list))))
		return (0);

	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem4->next = elem5;
	elem5->next = elem6;
	elem6->next = NULL;

	elem6->content = (void *)str;
	res = ft_lstlast(elem1);
	printf("\n%s\n", (char *)res->content);
}
*/