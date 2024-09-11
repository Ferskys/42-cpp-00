#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#define FG_YELLOW "\033[33m"
#define RESET "\033[0m"

#include <iostream>

namespace tests
{
	void shrubbery(void)
	{
		Bureaucrat workers[2] = {
			Bureaucrat("Intern", 150),
			Bureaucrat("CEO", 1)
		};
		ShrubberyCreationForm f1("Office");
		ShrubberyCreationForm f2(f1);
		ShrubberyCreationForm f3;

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		for (int i = 0; i < 2; i++) {
			workers[i].signForm(f1);
			workers[i].signForm(f2);
		}

		workers[1].executeForm(f3);
		f3 = f1;

		for (int i = 0; i < 2; i++) {
			workers[i].executeForm(f3);
		}
	}

	void robotomy(void)
	{
		Bureaucrat workers[2] = {
			Bureaucrat("Intern", 150),
			Bureaucrat("CEO", 1)
		};
		RobotomyRequestForm f1("Dennis DeYoung");
		RobotomyRequestForm f2(f1);
		RobotomyRequestForm f3;

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		for (int i = 0; i < 2; i++) {
			workers[i].signForm(f1);
			workers[i].signForm(f2);
		}

		workers[1].executeForm(f3);
		f3 = f1;

		for (int i = 0; i < 2; i++) {
			workers[i].executeForm(f3);
		}
	}

	void presidential(void)
	{
		Bureaucrat workers[2] = {
			Bureaucrat("Intern", 150),
			Bureaucrat("CEO", 1)
		};
		PresidentialPardonForm f1("Arthur Philip Dent");
		PresidentialPardonForm f2(f1);
		PresidentialPardonForm f3;

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		for (int i = 0; i < 2; i++) {
			workers[i].signForm(f1);
			workers[i].signForm(f2);
		}

		workers[1].executeForm(f3);
		f3 = f1;

		for (int i = 0; i < 2; i++) {
			workers[i].executeForm(f3);
		}
	}
}

int main (void)
{
	std::cout << FG_YELLOW "TREE TEST" RESET << std::endl;
	tests::shrubbery();
	std::cout << std::endl;
	std::cout << FG_YELLOW "ROBO TEST" RESET << std::endl;
	tests::robotomy();
	std::cout << std::endl;
	std::cout << FG_YELLOW "PRESIDENT TEST" RESET << std::endl;
	tests::presidential();
}