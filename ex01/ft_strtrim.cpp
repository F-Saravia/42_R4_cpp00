/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 23:23:20 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 18:33:05 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

std::string	ft_strtrim(const std::string& str)
{
	std::string::size_type	len = str.length();
	std::string::size_type	start = 0;
	std::string::size_type	end = len;

	start = 0;
	while (start < len
		&& std::isspace(static_cast<unsigned char>(str[start])))
		start++;
	end = len;
	while (end > start
		&& std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;
	return (str.substr(start, (end - start)));
}
