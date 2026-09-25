/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:40:43 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 00:13:12 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string				av_i("");
	std::string::size_type	len_avi = 0;
	std::string				str_to_print("");

	if (argc == 1)
		str_to_print = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc > 1)
	{
		for (int ac_i=1 ; ac_i<argc ; ac_i++)
		{
			av_i = argv[ac_i];
			len_avi = av_i.length();
			for (std::string::size_type i=0 ; i<len_avi ; i++)
				av_i[i] = 	static_cast<char>(
								std::toupper(
									static_cast<unsigned char>(av_i[i])
								)
							);
			str_to_print += av_i;
		}
	}
	std::cout << str_to_print << std::endl ;
	return (0);
}
