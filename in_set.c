/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:30:06 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/06 22:52:34 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_set(char c, char const *set)
{
	if (!c || !set)
		return (0);
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}
