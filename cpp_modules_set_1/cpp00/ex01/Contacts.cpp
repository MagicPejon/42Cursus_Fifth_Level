/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:26:10 by amalbrei          #+#    #+#             */
/*   Updated: 2023/07/06 20:17:33 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contact::Contact()
{
	this->_index = 0;
	this->_firstname = "\n";
	this->_lastname = "\n";
	this->_nickname = "\n";
	this->_phonenumber = "\n";
	this->_darkestsecret = "\n";
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::setindex(int index)
{
	this->_index = index;
}

int		Contact::setfirst()
{
	std::string input;
	
	std::cout << "First name: ";
	if (std::getline(std::cin, input))
	{
		while (this->check_empty(input, "First name: "))
		{	
			if (!(std::getline(std::cin, input)))
				return (1);
			
		}
		this->_firstname = input;
	}
	else
		return (1);
	return (0);
}

int		Contact::setlast()
{
	std::string input;
	
	std::cout << "Last name: ";
	if (std::getline(std::cin, input))
	{
		while (this->check_empty(input, "Last name: "))
		{	
			if (!(std::getline(std::cin, input)))
				return (1);
			
		}
		this->_lastname = input;
	}
	else
		return (1);
	return (0);
}

int		Contact::setnickname()
{
	std::string input;
	
	std::cout << "Nick-name: ";
	if (std::getline(std::cin, input))
	{
		while (this->check_empty(input, "Nick-name: "))
		{	
			if (!(std::getline(std::cin, input)))
				return (1);
			
		}
		this->_nickname = input;
	}
	else
		return (1);
	return (0);
}

int		Contact::setnumber()
{
	std::string input;
	
	std::cout << "Phone number: ";
	if (std::getline(std::cin, input))
	{
		while (this->check_empty(input, "Phone number: "))
		{	
			if (!(std::getline(std::cin, input)))
				return (1);
			
		}
		this->_phonenumber = input;
	}
	else
		return (1);
	return (0);
}

int		Contact::setsecret()
{
	std::string input;
	
	std::cout << "Darkest secret?: ";
	if (std::getline(std::cin, input))
	{
		while (this->check_empty(input, "Darkest secret?: "))
		{	
			if (!(std::getline(std::cin, input)))
				return (1);
			
		}
		this->_darkestsecret = input;
	}
	else
		return (1);
	return (0);
}

int	Contact::getindex()
{
	return (this->_index + 1);
}

std::string	Contact::getfirst()
{
	return (this->_firstname);
}

std::string	Contact::getlast()
{
	return (this->_lastname);
}

std::string Contact::getnickname()
{
	return (this->_nickname);
}

int	Contact::check_empty(std::string input, std::string message)
{
	int	i;
	
	i = 0;
	while(input[i] == ' ' || input[i] == '\t' || input[i] == '\n'
		|| input[i] == '\v' || input[i] == '\f' || input[i] == '\r')
		i++;
	if (input[i] == '\0')
	{
		std::cout << "Please add a valid input (just type anything beside spaces >.>)" << std::endl;
		std::cout << message;
		return (1);
	}
	return (0);
}

void	Contact::type_info()
{
	std::cout << "Index: " << this->_index + 1 << std::endl;
	std::cout << "First Name: " << this->_firstname << std::endl;
	std::cout << "Last Name: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phonenumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestsecret << std::endl;
}
