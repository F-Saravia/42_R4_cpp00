/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 23:26:34 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 18:42:11 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_HPP
# define LIBFT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <ctype.h>

bool		ft_str_iszero(const std::string& str);
bool		ft_str_isdigits(const std::string& str);
std::string	ft_strtrim(const std::string& str);
bool		ft_getline(
				std::ostream& out,
				const std::string& prompt,
				std::istream& in,
				std::string& line);

#endif // LIBFT_HPP