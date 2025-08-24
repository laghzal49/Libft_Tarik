/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:36:53 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/21 17:37:24 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int main()
{
	int arr[5] = {10, 20, 30, 40, 50};
	int *p = arr;
	printf("%d",*(p + 3));
	printf("%d",*(p + 4));

// Question:
// 1. Print the 3rd element using pointer arithmetic (no array indexing).
// 2. Increment the pointer to point to the 4th element, then print it.
}
