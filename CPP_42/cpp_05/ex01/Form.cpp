#include "Form.hpp"

// Constructors
Form::Form() : name("Unnamed"), isSigned(false), signGrade(150), execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other) 
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

// Assignment Operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecGrade() const {
    return execGrade;
}

// Signing the Form
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

// Exception Classes
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Output operator overload
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", form signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade();
    return os;
}