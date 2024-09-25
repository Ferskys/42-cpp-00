#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Criando um Bureaucrat e um Form
        Bureaucrat john("John", 50);
		std::cout << john.getName() << std::endl;
		std::cout << john.getGrade() << std::endl;
        Form taxForm("Tax Form", 45, 20);
		std::cout << taxForm.getName() << std::endl;
		std::cout << taxForm.getIsSigned() << std::endl;
		std::cout << taxForm.getSignGrade() << std::endl;
		std::cout << taxForm.getExecGrade() << std::endl;
		
        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;

        // Tentando assinar o formulário com um Bureaucrat com grade insuficiente
        john.signForm(taxForm);
        taxForm.beSigned(john);  // Isso vai lançar uma exceção
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // Assinando com um Bureaucrat com grade suficiente
        Bureaucrat alice("Alice", 40);
		std::cout << alice.getName() << std::endl;
		std::cout << alice.getGrade() << std::endl;
        Form report("Annual Report", 50, 30);

        alice.signForm(report);
        report.beSigned(alice);
        std::cout << report << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}