#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& that) : AForm("PresidentialPardonForm", 25, 5), _target("NoTarget") {
	*this = that;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {};

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& that) {
	if (this != &that) {
		AForm::operator=(that);
		const_cast<std::string&>(_target) = that._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) { // Corrected here
		throw NotSignedException();
	} else if (executor.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& form) {
	os << form.getName() << " (signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade() << ")";
	return (os);
}