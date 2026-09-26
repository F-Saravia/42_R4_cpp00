/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 17:57:36 by fasaravi          #+#    #+#             */
/*   Updated: 2026/09/26 22:02:36 by fasaravi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "libft.hpp"
#include <string>
#include <cstdlib>

static std::ostream&	output_usage(std::ostream& outstream)
{
	outstream << std::endl << "Available commands: 'ADD', 'SEARCH', 'EXIT'" << std::endl;
	return (outstream);
}

static void	set_contact(PhoneBook& phonebook)
{
	std::string	firstname = "";
	std::string	lastname = "";
	std::string	nickname = "";
	std::string	phonenumber = "";
	std::string	darkestsecret = "";
	bool		complete = true;
	bool		retry = false;
	std::string	str_retry = "";
	
	do
	{
		complete = true; retry = false;
		if (!ft_getline(std::cout, "Firstname: ", std::cin, firstname))
			return ;
		complete &= !(firstname.empty());
		if (!ft_getline(std::cout, "Lastname: ", std::cin, lastname))
			return ;
		complete &= !(lastname.empty());
		if (!ft_getline(std::cout, "Nickname: ", std::cin, nickname))
			return ;
		complete &= !(nickname.empty());
		if (!ft_getline(std::cout, "Phonenumber: ", std::cin, phonenumber))
			return ;
		complete &= !(phonenumber.empty());
		if (!ft_getline(std::cout, "Darkest Secret: ", std::cin, darkestsecret))
			return ;
		complete &= !(darkestsecret.empty());
		std::cout << std::endl;
		if (complete == false)
		{
			std::cout << "All fields must be filled." << std::endl;
			if (!ft_getline(std::cout, "Try again y/n?", std::cin, str_retry))
				return ;
			retry = (str_retry.compare("y") == 0 || str_retry.compare("Y") == 0);
			str_retry.clear();
		}
	} while(complete==false && retry == true);
	
	if (complete)
		phonebook.add(
			firstname, 
			lastname, 
			nickname, 
			phonenumber, 
			darkestsecret);
}

static void	search_contact(PhoneBook& phonebook)
{
	int				selection = -1;
	std::string		input = "";
	const Contact	*contact_ptr = NULL;

	phonebook.to_outstream(std::cout);
	if (phonebook.isempty())
		return ;
	if (!ft_getline(std::cout, "Selection: ", std::cin, input))
		return;
	if (!ft_str_isdigits(input))
		selection = -1;
	else
		selection = std::atoi(input.c_str());
	if (selection == 0 && !ft_str_iszero(input))
		selection = -1;
	contact_ptr = phonebook.search_byId(selection);
	if (contact_ptr == NULL)
		std::cout << "Incorrect selection." << std::endl;
	else
		contact_ptr->to_outstream_long(std::cout);
}

static void	interactive_phonebook(PhoneBook& phonebook)
{
	std::string	command = "";
	
	while(1)
	{
		output_usage(std::cout);
		if (!ft_getline(std::cout, "Enter a command: ", std::cin, command))
    		return;
		if (command.compare("ADD") == 0)
			set_contact(phonebook);
		else if (command.compare("SEARCH") == 0)
			search_contact(phonebook);
		else if (command.compare("EXIT") == 0)
			return ;
		else
			std::cout << "Command not found : \'" << command << "\'" << std::endl;
	}
}

int	main(void)
{
	PhoneBook	phonebook;

	interactive_phonebook(phonebook);
	return (0);
}
