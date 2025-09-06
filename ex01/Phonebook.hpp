/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:01:02 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/09/05 16:16:39 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class Phonebook
{
	private:
		Contact	_contact[8];
		int		_current_i;
		bool	_time_to_exit;

	public:
		Phonebook();
		~Phonebook();
		bool	getTimeToExit() const;
		void	setTimeToExit();
		int		getCurrentI() const;
		void	setCurrentI();
		void	add();
		void	search();
		void	exit();
};

#endif