/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:34:51 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 22:26:55 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
: size(0), last_id(-1)
{
}

bool			PhoneBook::isempty(void) const
{
	return (this->size == 0);
}

void			PhoneBook::add(
					const std::string& firstname, 
					const std::string& lastname, 
					const std::string& nickname, 
					const std::string& phonenumber, 
					const std::string& darkestsecret 
				)
{
	if (MAX_CONTACTS < 1)
	{
		this->size += 1;
		this->last_id += 1;
	}
	else
	{
		if (this->size < MAX_CONTACTS)
			this->size += 1;
		this->last_id = (this->last_id + 1) % MAX_CONTACTS;
	}
	this->contacts[this->last_id] = Contact(
							this->last_id, 
							firstname, 
							lastname, 
							nickname, 
							phonenumber, 
							darkestsecret);
}

const Contact*	PhoneBook::search_byId(int id) const
{
	if (id < 0 || id >= this->size)
		return (NULL);
	return (&(this->contacts[id]));
}

std::ostream&	PhoneBook::to_outstream(std::ostream& outsteram) const
{
	if (this->isempty()){
		outsteram << "The phonebook is empty" ;
		return (outsteram);
	}
	outsteram << "|" << std::right << std::setw(CONTACT_FMTFIELD_WIDTH) << ft_str_truncend("ID", CONTACT_FMTFIELD_WIDTH, '.') ;
	outsteram << "|" << std::right << std::setw(CONTACT_FMTFIELD_WIDTH) << ft_str_truncend("Firstname", CONTACT_FMTFIELD_WIDTH, '.') ;
	outsteram << "|" << std::right << std::setw(CONTACT_FMTFIELD_WIDTH) << ft_str_truncend("Lastname", CONTACT_FMTFIELD_WIDTH, '.') ;
	outsteram << "|" << std::right << std::setw(CONTACT_FMTFIELD_WIDTH) << ft_str_truncend("Nickname", CONTACT_FMTFIELD_WIDTH, '.') ;
	outsteram << "|" << std::endl;
	for (int i=0 ; i < this->size ; i++)
		this->contacts[i].to_outstream_short(outsteram);
	outsteram << std::endl;
	return (outsteram);
}
