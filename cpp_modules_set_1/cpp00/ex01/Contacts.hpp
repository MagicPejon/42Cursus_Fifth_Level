/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:06:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/07/06 20:07:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_H
# define CONTACTS_H

#include <iostream>
#include <string>

class Contact
{

private:
	int			_index;
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestsecret;

public:

	Contact(void);
	~Contact(void);
	void		setindex(int index);
	int			setfirst(void);
	int			setlast(void);
	int			setnickname(void);
	int			setnumber(void);
	int			setsecret(void);
	int			getindex(void);
	std::string	getfirst(void);
	std::string	getlast(void);
	std::string	getnickname(void);
	int			check_empty(std::string input, std::string message);
	void		type_info(void);


};

#endif