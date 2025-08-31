/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:45:00 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/31 04:39:58 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Example demonstrating libft capabilities
** Compile with: gcc -Wall -Wextra -Werror example.c -L. -lft -o example
*/

#include "libft.h"
#include <stdio.h>

void	demo_string_operations(void)
{
	char	*str;
	char	**words;
	int		i;

	ft_putendl_fd("=== String Operations Demo ===", 1);
	
	// String creation and manipulation
	str = ft_strjoin("Hello", " World!");
	ft_putstr_fd("Created string: ", 1);
	ft_putendl_fd(str, 1);
	
	// String splitting
	words = ft_split(str, ' ');
	ft_putendl_fd("Split into words:", 1);
	i = 0;
	while (words[i])
	{
		ft_putstr_fd("  - ", 1);
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	free(str);
	
	// Number conversion
	str = ft_itoa(42);
	ft_putstr_fd("Number 42 as string: ", 1);
	ft_putendl_fd(str, 1);
	free(str);
}

void	demo_linked_list(void)
{
	t_list	*list;
	t_list	*node;
	int		*data;
	int		i;

	ft_putendl_fd("\n=== Linked List Demo ===", 1);
	
	list = NULL;
	
	// Create and add nodes
	for (i = 1; i <= 3; i++)
	{
		data = malloc(sizeof(int));
		*data = i * 10;
		node = ft_lstnew(data);
		ft_lstadd_back(&list, node);
	}
	
	ft_putstr_fd("List size: ", 1);
	ft_putnbr_fd(ft_lstsize(list), 1);
	ft_putchar_fd('\n', 1);
	
	ft_putendl_fd("List contents:", 1);
	node = list;
	while (node)
	{
		ft_putstr_fd("  - ", 1);
		ft_putnbr_fd(*(int *)node->content, 1);
		ft_putchar_fd('\n', 1);
		node = node->next;
	}
	
	// Clean up
	ft_lstclear(&list, free);
}

void	demo_memory_operations(void)
{
	char	*memory;
	char	*copy;

	ft_putendl_fd("\n=== Memory Operations Demo ===", 1);
	
	// Allocate and set memory
	memory = ft_calloc(10, sizeof(char));
	ft_memset(memory, 'A', 5);
	memory[5] = '\0';
	
	ft_putstr_fd("Memory content: ", 1);
	ft_putendl_fd(memory, 1);
	
	// Copy memory
	copy = malloc(6);
	ft_memcpy(copy, memory, 6);
	ft_putstr_fd("Copied content: ", 1);
	ft_putendl_fd(copy, 1);
	
	free(memory);
	free(copy);
}

int	main(void)
{
	ft_putendl_fd("🚀 Libft Premium Demo 🚀", 1);
	ft_putendl_fd("========================", 1);
	
	demo_string_operations();
	demo_linked_list();
	demo_memory_operations();
	
	ft_putendl_fd("\n✅ All demos completed successfully!", 1);
	ft_putendl_fd("💎 This libft is ready for production use!", 1);
	
	return (0);
}
