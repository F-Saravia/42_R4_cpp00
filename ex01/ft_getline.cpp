/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 23:28:10 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 18:45:06 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

bool	ft_getline(
			std::ostream& out,
			const std::string& prompt,
			std::istream& in,
			std::string& line)
{
	if (!prompt.empty())
		out << prompt;
	if (!std::getline(in, line))
	{
		std::cerr << "Error while reading input." << std::endl;
		return (false);
	}
	line = ft_strtrim(line);
	return (true);
}
