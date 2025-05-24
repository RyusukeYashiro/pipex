/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:20:52 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/04/27 15:03:20 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}

// #include <stdio.h>
// int main(void)
// {
//     t_list *new_node;
//     t_list *new_list = NULL;

//     char data1[10] = "hello";
//     char data2[10] = "42";
//     char data3[10] = "tokyo!!!";

//     new_node = ft_lstnew(data1);
//     *new_list = *new_node;

//     *new_list->next = ft_lstnew(data2);
//     *new_list = *new_list->next;

//     *new_list->next = ft_lstnew(data3);
//     *new_list = *new_node;
//     while(*new_list != NULL)
//     {
//         printf("%s\n", (char *)*new_list->content);
//         *new_list = *new_list->next;
//     }
//     return(0);
// }