/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:29:43 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 18:42:25 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
# include <cstddef>
# define CONTACT_FMTFIELD_WIDTH 10

class Contact
{
	private:
		int				id;
		std::string 	firstname;
		std::string 	lastname;
		std::string 	nickname;
		std::string 	phonenumber;
		std::string 	darkestsecret;

	public:
		Contact();
		Contact(
			int	id,
			std::string firstname, 
			std::string lastname, 
			std::string nickname, 
			std::string phonenumber, 
			std::string darkestsecret 
		);
		Contact& 		operator=(const Contact& to_copy);
		std::ostream&	to_outstream_short(std::ostream& outsteram);
		std::ostream&	to_outstream_long(std::ostream& outsteram);
};


#endif //CONTACT_HPP