/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:34:51 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 21:26:17 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# define MAX_CONTACTS 8

class PhoneBook
{
	private :
		int		size;
		int		last_id;
		Contact	contacts[MAX_CONTACTS];
	
	public :
		PhoneBook();
		bool			isempty(void) const;
		void			add(
							const std::string& firstname, 
							const std::string& lastname, 
							const std::string& nickname, 
							const std::string& phonenumber, 
							const std::string& darkestsecret 
						);
		Contact			*search_byId(int id);
		std::ostream&	to_outstream(std::ostream& outsteram) const;
};

#endif //PHONEBOOK_HPP