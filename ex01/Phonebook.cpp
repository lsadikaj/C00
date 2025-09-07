/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:14:25 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/09/07 15:43:52 by lsadikaj         ###   ########.fr       */
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
	int	valid_contact = 0;

	for (int i = 0; i < 8; i++)
	{
		if (!_contact[i].getFirstName().empty())
			valid_contact++;
	}
	if (valid_contact == 0)
	{
		std::cout << "The phonebook is empty, try 'ADD' first" << std::endl;
		return ;
	}

    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First name" << "|";
    std::cout << std::setw(10) << std::right << "Last name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		if (!_contact[i].getFirstName().empty())
		{
			std::string	first_name(_contact[i].getFirstName());
			std::string	last_name(_contact[i].getLastName());
			std::string	nickname(_contact[i].getNickName());
			
			if (first_name.length() > 10)
				first_name = first_name.substr(0, 9) + ".";
			if (last_name.length() > 10)
				last_name = last_name.substr(0, 9) + ".";
			if (nickname.length() > 10)
				nickname = nickname.substr(0, 9) + ".";

			std::cout << std::setw(10) << std::right << i << "|";
			std::cout << std::setw(10) << std::right << first_name << "|";
			std::cout << std::setw(10) << std::right << last_name << "|";
			std::cout << std::setw(10) << std::right << nickname << std::endl;
		}
	}
	int		choosen_index;
	bool	valid_choice = false;

	while (!valid_choice)
	{
		std::cout << "Enter the index of the contact you want to display : ";
		std::cin >> choosen_index;

		if (choosen_index < 0 || choosen_index >= 8)
		{
			std::cout << "Use a index between 0 and 7" << std::endl;
			continue ;
		}
		if (_contact[choosen_index].getFirstName().empty())
		{
			std::cout << "Try a smaller index, that appears in the array" << std::endl;
			continue ;
		}
		valid_choice = true;
	}
	std::cout << "=== Contact infos ====" << std::endl;
	std::cout << "First name : " << _contact[choosen_index].getFirstName() << std::endl;
	std::cout << "Last name : " << _contact[choosen_index].getLastName() << std::endl;
	std::cout << "Nickname : " << _contact[choosen_index].getNickName() << std::endl;
	std::cout << "Phone number : " << _contact[choosen_index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << _contact[choosen_index].getDarkestSecret() << std::endl;
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