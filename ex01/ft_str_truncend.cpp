/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_truncend.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 22:21:29 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 22:25:27 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

std::string ft_str_truncend(
				const std::string& str,
				const std::string::size_type field_size,
				const char append_printable_end)
{
	if (field_size > 1 && str.length() > field_size)
	{
		if (std::isprint(static_cast<unsigned char>(append_printable_end)))
			return (str.substr(0, (field_size - 1)) + append_printable_end);
		return (str.substr(0, (field_size)));
	}
	return (str);
}