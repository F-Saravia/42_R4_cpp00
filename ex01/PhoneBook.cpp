/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:34:51 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 18:17:19 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
: size(0), last_id(-1)
{
}

bool			PhoneBook::isempty(void)
{
	return (this->size == 0);
}

void			PhoneBook::add(
					std::string firstname, 
					std::string lastname, 
					std::string nickname, 
					std::string phonenumber, 
					std::string darkestsecret 
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

Contact*			PhoneBook::search_byId(int id)
{
	if (id < 0 || id >= this->size)
		return (NULL);
	return (&(this->contacts[id]));
}

static std::string truncate_field(const std::string& str)
{
	if (CONTACT_FMTFIELD_WIDTH > 1 && str.length() > CONTACT_FMTFIELD_WIDTH)
		return (str.substr(0, (CONTACT_FMTFIELD_WIDTH - 1)) += '.');
	return (str);
}

std::ostream&	PhoneBook::to_outstream(std::ostream& outsteram)
{
	if (this->isempty()){
		outsteram << "The phonebook is empty" ;
		return (outsteram);
	}
	outsteram << "|" << std::right << std::setw(10) << truncate_field("ID") ;
	outsteram << "|" << std::right << std::setw(10) << truncate_field("Firstname") ;
	outsteram << "|" << std::right << std::setw(10) << truncate_field("Lastname") ;
	outsteram << "|" << std::right << std::setw(10) << truncate_field("Nickname") ;
	outsteram << "|" << std::endl;
	for (int i=0 ; i < this->size ; i++)
		this->contacts[i].to_outstream_short(outsteram);
	outsteram << std::endl;
	return (outsteram);
}
