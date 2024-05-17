/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:31:52 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/17 12:43:18 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "zombieHorde.hpp"

#include <string> // Para usar funções de string

int main() {
    int N = 5;
    std::string name = "Zombie";

    Zombie* horde = zombieHorde(N, name);

    // Usando um loop para chamar announce para cada zumbi
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    delete[] horde; // Deleta todos os zumbis
    return 0;
}