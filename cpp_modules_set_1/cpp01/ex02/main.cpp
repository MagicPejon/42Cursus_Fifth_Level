/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:29:14 by amalbrei          #+#    #+#             */
/*   Updated: 2023/07/09 15:56:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string subject = "HI THIS IS BRAIN";
	std::string* stringPTR = &subject;
	std::string& stringREF = subject;
	
	std::cout << &subject << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << subject << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	
	return (0);
}