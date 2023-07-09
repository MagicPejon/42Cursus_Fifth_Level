/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:49:59 by amalbrei          #+#    #+#             */
/*   Updated: 2023/07/09 15:07:35 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <iomanip>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(void);
		~Zombie(void);
		void	setname(std::string name);
		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif