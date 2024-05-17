/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:30:42 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/17 12:41:25 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void announce() const;
    void setName(std::string name);

private:
    std::string name;
};
