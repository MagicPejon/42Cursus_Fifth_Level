/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:19:15 by amalbrei          #+#    #+#             */
/*   Updated: 2023/07/07 15:46:37 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "Contacts.hpp"

class PhoneBook
{

private:
	Contact		_contacts[8];
	int			_index;
	int			_maxindex;
	std::string	_add;
	std::string	_search;
	std::string	_exit;

public:
	std::string	input;
	int			choice;
	
	PhoneBook(int choice, std::string add, std::string search, std::string exit);
	~PhoneBook(void);
	int		compare(std::string target);
	int		get_maxindex(void);
	Contact	get_contact(int index);
	void	add_contact(Contact contact);
	int		display_list(void);
	int		search_list(void);


};


#endif