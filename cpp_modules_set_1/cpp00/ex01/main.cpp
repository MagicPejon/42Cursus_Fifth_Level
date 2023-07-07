/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:36:28 by amalbrei          #+#    #+#             */
/*   Updated: 2023/07/07 15:47:16 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	int			i;
	PhoneBook	phonebook(0, "ADD", "SEARCH", "EXIT");
	Contact		contact;

	i = 0;
	std::cout << "------------------------" << std::endl;
	std::cout << "                      " << std::endl;
	std::cout << "Please enter a command: " << std::endl;
	std::cout << "                      " << std::endl;
	std::cout << "------------------------" << std::endl;
	while (1)
	{
		std::cout << "INPUT(ADD/SEARCH/EXIT): ";
		if (!(std::getline(std::cin, phonebook.input)))
		{
			std::cout << std::endl;
			std::cout << "Closing and deleting phonebook, have a nice day :D" << std::endl;
			break ;
		}
		phonebook.choice = phonebook.compare(phonebook.input);
		if (phonebook.choice == 1)
		{
			contact.setindex(i);
			if (contact.setfirst() || contact.setlast() || contact.setnickname()
				|| contact.setnumber() || contact.setsecret())
			{
				std::cout << std::endl;
				std::cout << "Closing and deleting phonebook, have a nice day :D" << std::endl;
				break ;
			}
			phonebook.add_contact(contact);
			i++;
			if (i == 8)
			{
				std::cout << "PHONEBOOK IS FULL, NEXT ADD WILL REPLACE OLDEST INDEXES" << std::endl;
				i = 0;
			}
		}
		else if (phonebook.choice == 2)
		{
			if (phonebook.display_list())
			{
				if (phonebook.search_list())
				{
					std::cout << std::endl;
					std::cout << "Closing and deleting phonebook, have a nice day :D" << std::endl;
					break ;
				}
			}
		}
		else if (phonebook.choice == 3)
		{
			std::cout << "Deleting phonebook and exiting..." << std::endl;
			break ;
		}
		else
			std::cout << "Wrong input... try again... (pst... its case sensitive :<)" << std::endl;
	}
	return (0);
}