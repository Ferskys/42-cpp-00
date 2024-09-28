#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#define FG_YELLOW "\033[33m"
#define RESET "\033[0m"

#include <iostream>

namespace tests
{
	void payday(void)
	{
		Intern someone;
		AForm *form = someone.makeForm("shrubbery creation", "apartament");
		AForm *form2 = someone.makeForm("robotomy request", "Bender");
		AForm *form3 = someone.makeForm("presidential pardon", "Marvin");
		Bureaucrat boss("Boss", 1);

		boss.signForm(*form);
		boss.executeForm(*form);
		boss.signForm(*form2);
		boss.executeForm(*form2);
		boss.signForm(*form3);
		boss.executeForm(*form3);

		delete form;
		delete form2;
		delete form3;
	}

	void day1(void)
	{
		Intern other;
		AForm* wrongForm = other.makeForm("promotion request", "Sponge Bob");

		if (wrongForm) {
			std::cout << "Isn't null??????" << std::endl;
		} else {
			std::cout << "NULL" << std::endl;
		}
	}
}

int main (void)
{
	std::cout << FG_YELLOW "VALID TEST" RESET << std::endl;
	tests::payday();
	std::cout << std::endl;
	std::cout << FG_YELLOW "INVALID TEST" RESET << std::endl;
	tests::day1();
}