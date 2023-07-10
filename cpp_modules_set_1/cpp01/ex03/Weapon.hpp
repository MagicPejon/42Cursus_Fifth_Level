/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:59:13 by amalbrei          #+#    #+#             */
/*   Updated: 2023/07/09 16:22:05 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon(void);
		const Weapon getType(void);
		void setType(std:string input);
}

#endif