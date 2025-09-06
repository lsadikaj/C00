/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:14:25 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/09/06 15:39:52 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook() : _current_i(0), _time_to_exit(false)
{
	// std::cout << "Constructor from Phonebook called !" << std::endl;
}

Phonebook::~Phonebook()
{
	// std::cout << "Destructor from Phonebook called !" << std::endl;
}

bool	Phonebook::getTimeToExit() const
{
	return (_time_to_exit);
}

void	Phonebook::setTimeToExit(void)
{
	_time_to_exit = true;
}

int		Phonebook::getCurrentI() const
{
	return (_current_i);
}

void	Phonebook::setCurrentI()
{
	// pour incrémenter de manière circulaire et
	// que le plus récent remplace chaque fois le 
	// plus ancien une fois les 8 contacts plein
	_current_i = (_current_i + 1) % 8;
}

void	Phonebook::add()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;
	

	std::cout << "Add a new contact" << std::endl;
	
	do
	{
		std::cout << "Enter the first name : ";
		std::getline(std::cin, first_name);
	} while (first_name.empty());
	_contact[_current_i].setFirstName(first_name);
	
	do
	{
		std::cout << "Enter the last name : ";
		std::getline(std::cin, last_name);
	} while (last_name.empty());
	_contact[_current_i].setLastName(last_name);
	
	do
	{
		std::cout << "Enter the nickname : ";
		std::getline(std::cin, nick_name);
	} while (nick_name.empty());
	_contact[_current_i].setNickName(nick_name);

	do
	{
		std::cout << "Enter the phone number : ";
		std::getline(std::cin, phone_number);
	} while (phone_number.empty());
	_contact[_current_i].setPhoneNumber(phone_number);

	do
	{
		std::cout << "Enter the darkest secret : ";
		std::getline(std::cin, darkest_secret);
	} while (darkest_secret.empty());
	_contact[_current_i].setDarkestSecret(darkest_secret);
	
	setCurrentI();
}

void	Phonebook::search()
{
	
}

void	Phonebook::exit()
{
	std::string	answer;
	std::string	yes("YES");
	
	std::cout << "Are you sure you want to quit ?" << std::endl;
	std::cout << "Tape YES to quit definitily : ";
	std::cin >> answer;
	if (answer == yes)
		// pour quitter la boucle dans le main
		// et que ca soit le main qui quitte
		setTimeToExit();
}