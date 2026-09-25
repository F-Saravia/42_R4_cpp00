/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_iszero.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 01:02:08 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 18:33:50 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

bool	ft_str_iszero(const std::string& str)
{
	if (str.empty())
		return (false);
	std::string::size_type	len = str.length();
	for (size_t i=0 ; i<len ; i++)
	{
		if (str[i] != '0')
			return (false);
	}
	return (true);
}
