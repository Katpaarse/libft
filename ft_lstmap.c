/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerste <jukerste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:58:02 by kat               #+#    #+#             */
/*   Updated: 2025/02/27 14:56:44 by jukerste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list = NULL;
	t_list	*new_node;
	void	*new_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

int main(void)
{
    t_list *new;
    t_list *head;

    head = ft_lstnew(strdup("hello"));
    new = head;
    new->next = ft_lstnew(strdup("world"));
    new->next->next = ft_lstnew(strdup("how"));
    new->next->next->next = ft_lstnew(strdup("are"));
    new->next->next->next->next = ft_lstnew(strdup("you"));

    printf("Original list:\n");
    print_list(new);

    // Map the function to the list
    t_list *new_list = ft_lstmap(new, to_uppercase, del);

    // Print the new list
    printf("Mapped list:\n");
    print_list(new_list);

    // Free allocated memory
    ft_lstclear(&new, del);
    ft_lstclear(&new_list, del);

    return 0;
}