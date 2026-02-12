/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:18 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/11 15:11:40 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
typename T::iterator	easyfind(T& c, int value)
{
	typename T::iterator it;

	for (typename T::iterator it = c.begin(); it != c.end(); ++it)
	{
		if (*it == value)
			return it;
	}
	return c.end();
}

#endif // EASYFIND_TPP
