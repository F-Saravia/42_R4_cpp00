/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:29:43 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 21:18:22 by fasaravi         ###   ########.fr       */
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
			int id,
			const std::string& firstname, 
			const std::string& lastname, 
			const std::string& nickname, 
			const std::string& phonenumber, 
			const std::string& darkestsecret 
		);
		Contact& 			operator=(const Contact& to_copy);
		const std::string&	getFirstname(void) const;
		const std::string&	getLastname(void) const;
		const std::string&	getNickname(void) const;
		const std::string&	getPhonenumber(void) const;
		const std::string&	getDarkestsecret(void) const;
		std::ostream&		to_outstream_short(std::ostream& outsteram) const;
		std::ostream&		to_outstream_long(std::ostream& outsteram) const;
};


#endif //CONTACT_HPP