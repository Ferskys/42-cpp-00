/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:26:01 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/18 23:36:05 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <string>

class HumanB {
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB(const std::string &name);
    void setWeapon(Weapon &weapon);
    void attack() const;
};