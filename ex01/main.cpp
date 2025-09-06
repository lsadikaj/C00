/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:22:39 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/09/06 00:04:41 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main()
{
	Phonebook	repertoir;
	std::string	reponse;
	std::string	add("ADD");
	std::string	search("SEARCH");
	std::string	exit("EXIT");
	
	std::cout << " *** WELCOME IN MY AWESOME PHONEBOOK ***" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "You have 3 option you can use" << std::endl;
	std::cout << " - 'ADD' to add a new contact" << std::endl;
	std::cout << " - 'SEARCH' to search a contact" << std::endl;
	std::cout << " - 'EXIT' to exit the phonebook" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	while (!repertoir.getTimeToExit())
	{
		std::cout << "Tape your choice <ADD> <SEARCH> <EXIT> : ";
		std::cin >> reponse;
		std::cin.ignore();
		if (reponse == add)
			repertoir.add();	
		else if (reponse == search)
			repertoir.search();
		else if (reponse == exit)
			repertoir.exit();
		else
		{
			std::cout << "The only 3 possible usage are: 'ADD' 'SEARCH' 'EXIT'" << std::endl;
			continue ;
		}
	}
	return(0);
}