/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:40:39 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 22:27:56 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
:	id(-1)
{
}

Contact::Contact(
			int	id,
			const std::string& firstname, 
			const std::string& lastname, 
			const std::string& nickname, 
			const std::string& phonenumber, 
			const std::string& darkestsecret)
:	id(id),
	firstname(firstname),
	lastname(lastname),
	nickname(nickname),
	phonenumber(phonenumber),
	darkestsecret(darkestsecret)
{
}

Contact&	Contact::operator=(const Contact& to_copy)
{
	this->id = to_copy.id;
	this->firstname = to_copy.firstname;
	this->lastname = to_copy.lastname;
	this->nickname = to_copy.nickname;
	this->phonenumber = to_copy.phonenumber;
	this->darkestsecret = to_copy.darkestsecret;
	return (*this);
}

std::ostream&	Contact::to_outstream_short(std::ostream& outsteram) const
{
	outsteram << "|" << std::right << std::setw(CONTACT_FMTFIELD_WIDTH) << this->id ;
	outsteram << "|" << std::right << std::setw(CONTACT_FMTFIELD_WIDTH) << ft_str_truncend(this->firstname, CONTACT_FMTFIELD_WIDTH, '.') ;
	outsteram << "|" << std::right << std::setw(CONTACT_FMTFIELD_WIDTH) << ft_str_truncend(this->lastname, CONTACT_FMTFIELD_WIDTH, '.') ;
	outsteram << "|" << std::right << std::setw(CONTACT_FMTFIELD_WIDTH) << ft_str_truncend(this->nickname, CONTACT_FMTFIELD_WIDTH, '.') ;
	outsteram << "|" << std::endl;
	return (outsteram);
}

std::ostream&	Contact::to_outstream_long(std::ostream& outsteram) const
{
	outsteram << "ID: " << this->id << std::endl;
	outsteram << "Firstname: " << this->firstname << std::endl;
	outsteram << "Lastname: " << this->lastname << std::endl;
	outsteram << "Nickname: " << this->nickname << std::endl;
	outsteram << "Phone Number: " << this->phonenumber << std::endl;
	outsteram << "Darkest Secret: " << this->darkestsecret << std::endl;
	outsteram << std::endl;
	return (outsteram);
}

const std::string&	Contact::getFirstname(void) const
{
	return (this->firstname);
}

const std::string&	Contact::getLastname(void) const
{
	return (this->lastname);
}

const std::string&	Contact::getNickname(void) const
{
	return (this->nickname);
}

const std::string&	Contact::getPhonenumber(void) const
{
	return (this->phonenumber);
}

const std::string&	Contact::getDarkestsecret(void) const
{
	return (this->darkestsecret);
}
