#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

/* TRUCTORS ================================================================= */
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("NoTarget") {};
RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {};
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& that) : AForm("RobotomyRequestForm", 72, 45), _target("NoTarget") { *this = that; }
RobotomyRequestForm::~RobotomyRequestForm(void) {};

/* OPERATORS ================================================================ */
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& that) {
    if (this != &that) {
        AForm::operator=(that);
        const_cast<std::string&>(_target) = that._target;
    }
    return (*this);
}

/* METHODS ================================================================== */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const throw(GradeTooLowException, NotSignedException, std::ios_base::failure) {
    if (!getIsSigned()) { // Corrected here
        throw NotSignedException();
    } else if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }
    srand(time(NULL));
    std::cout << "* Vrrrrrrrrrrrrrr *" << std::endl;
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << _target << " hasn't been robotomized!" << std::endl;
    }
}