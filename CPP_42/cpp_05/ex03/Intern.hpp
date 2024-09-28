#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target);

private:
    AForm *createFormShrubbery(const std::string &target);
    AForm *createFormRobotomy(const std::string &target);
    AForm *createFormPardon(const std::string &target);

    AForm *createForm(const std::string &formName, const std::string &target);
};

std::ostream&	operator<<(std::ostream& os, Intern const& intern);