/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:25:01 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/18 23:34:32 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string &type);
    const std::string& getType() const;
    void setType(const std::string &type);
};