#include "ShrubberyCreationForm.hpp"
#include <fstream>

#define TREES "\
       _-_               _-_               _-_\n\
    /~~   ~~\\         /~~   ~~\\         /~~   ~~\\\n\
 /~~         ~~\\   /~~         ~~\\   /~~         ~~\\\n\
{               } {               } {               }\n\
 \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  /\n\
   ~  \\ //  ~        ~  \\ //  ~        ~  \\ //  ~\n\
_- -   | | _- _   _- -   | | _- _   _- -   | | _- _\n\
  _ -  | |   -_     _ -  | |   -_     _ -  | |   -_\n\
      // \\              // \\              // \\\
"

void drawTree(std::string const& fileName) throw(std::ios_base::failure);

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("NoTarget") {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& that) : AForm("ShrubberyCreationForm", 145, 137), _target("NoTarget") {
    *this = that;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& that) {
    if (this != &that) {
        AForm::operator=(that);
        const_cast<std::string&>(_target) = that._target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned()) { // Corrected here
        throw AForm::NotSignedException();
    } else if (executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    drawTree(_target + "_shrubbery");
}

void drawTree(std::string const& fileName) throw(std::ios_base::failure) {
    std::ofstream out(fileName.c_str(), std::ios::out | std::ios::trunc);
    if (!out.is_open() || out.fail()) {
        throw std::ios_base::failure("Error opening file");
    }
    out << TREES << std::endl;
    if (out.fail()) {
        throw std::ios_base::failure("Error writing to file");
    }
    out.close();
    if (out.fail()) {
        throw std::ios_base::failure("Error closing file");
    }
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& form) {
    os << "ShrubberyCreationForm " << form.getName() << " (signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade() << ")";
    return (os);
}