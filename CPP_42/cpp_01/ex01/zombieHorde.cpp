/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:31:42 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/17 12:33:27 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string> // Para usar funções de string

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];

    // Inicializando os zumbis usando um loop
    for (int i = 0; i < N; ++i) {
        horde[i].setName(name);
    }

    return horde;
}