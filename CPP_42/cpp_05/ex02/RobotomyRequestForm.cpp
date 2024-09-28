#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("NoTarget") {};
RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {};
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& that) : AForm("RobotomyRequestForm", 72, 45), _target("NoTarget") { *this = that; }
RobotomyRequestForm::~RobotomyRequestForm(void) {};

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& that) {
    if (this != &that) {
        AForm::operator=(that);
        const_cast<std::string&>(_target) = that._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
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

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& form) {
    os << form.getName() << " (signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade() << ")";
    return (os);
}