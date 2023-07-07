/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:19:11 by amalbrei          #+#    #+#             */
/*   Updated: 2023/07/07 15:48:10 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int choice, std::string add, std::string search, std::string exit)
{
	this->choice = choice;
	this->_add = add;
	this->_search = search;
	this->_exit = exit;
	this->_index = 0;
	this->_maxindex = 0;
	return;
}

PhoneBook::~PhoneBook()
{
	return;
}

int PhoneBook::compare(std::string target)
{
	int	i;

	i = 0;
	while(1)
	{
		if (target[i] == this->_add[i] && this->_add[i])
			i++;
		if (target[i] == this->_add[i] && !this->_add[i])
			return (1);
		else if (target[i] != this->_add[i])
		{
			i = 0;
			break ;
		}
	}
	while(1)
	{
		if (target[i] == this->_search[i] && this->_search[i])
			i++;
		else if (target[i] == this->_search[i])
			return (2);
		else
		{
			i = 0;
			break ;
		}
	}
	while(1)
	{
		if (target[i] == this->_exit[i] && this->_exit[i])
			i++;
		else if (target[i] == this->_exit[i])
			return (3);
		else
		{
			i = 0;
			break ;
		}
	}
	return (0);
}

int	PhoneBook::get_maxindex()
{
	return (this->_maxindex);
}

Contact PhoneBook::get_contact(int index)
{
	return(this->_contacts[index]);
}

void	PhoneBook::add_contact(Contact contact)
{
	this->_contacts[this->_index] = contact;
	std::cout << "Contact added to book" << std::endl;
	this->_index++;
	this->_maxindex++;
	if (this->_index == 8)
		this->_index = 0;
	if (this->_maxindex > 8)
		this->_maxindex = 8;
}

int	PhoneBook::display_list()
{
	int	index_l;

	index_l = 0;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	if (this->_maxindex == 0)
	{
		std::cout << "Phonebook is currently empty, please use \"ADD\" to fill" << std::endl;
		return (0);
	}
	else
	{
		while (index_l < this->_maxindex)
		{
			std::cout << "|         ";
			std::cout << this->_contacts[index_l].getindex();
			std::cout << "|";
			if (this->_contacts[index_l].getfirst().length() > 10)
				std::cout << this->_contacts[index_l].getfirst().substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << this->_contacts[index_l].getfirst();
			std::cout << "|";
			if (this->_contacts[index_l].getlast().length() > 10)
				std::cout << this->_contacts[index_l].getlast().substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << this->_contacts[index_l].getlast();
			std::cout << "|";
			if (this->_contacts[index_l].getnickname().length() > 10)
				std::cout << this->_contacts[index_l].getnickname().substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << this->_contacts[index_l].getnickname();
			std::cout << "|" << std::endl;
			index_l++;
		}
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	return (1);
}

int	PhoneBook::search_list()
{
	std::string input;

	std::cout << "Which contact would you like to search?: ";
	if (!(std::getline(std::cin, input)))
		return (1);
	if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
	{
		if (input[0] - '0' <= this->_maxindex)
			this->_contacts[input[0] - '1'].type_info();
		else
			std::cout << "Contact doesn't exist..." << std::endl;
	}
	else
		std::cout << "Invalid index... pay attention :/" << std::endl;
	return (0);
}
