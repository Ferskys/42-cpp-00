#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

// Constructors
AForm::AForm() : name("JustAForm"), isSigned(false), signGrade(150), execGrade(150) {
    srand(time(NULL));
    const_cast<int&>(signGrade) = rand() % 151 + 1;
    const_cast<int&>(execGrade) = rand() % 151 + 1;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
        throw GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw GradeTooLowException();
    }
}

// Copy Constructor
AForm::AForm(const AForm& other) : name("JustAForm"), isSigned(false), signGrade(150), execGrade(150) {
    *this = other;
}

// Assignment Operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        const_cast<std::string&>(name) = other.getName();
        const_cast<int&>(signGrade) = other.getSignGrade();
        const_cast<int&>(execGrade) = other.getExecGrade();
        isSigned = other.getIsSigned();
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
const std::string& AForm::getName() const {
    return name;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecGrade() const {
    return execGrade;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

// Signing the AForm
void AForm::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > signGrade) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

// Exception Classes
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Output operator overload
std::ostream& operator<<(std::ostream& oStream, const AForm& form) {
    oStream << "Form_name: " << form.getName()
            << ", sign_grade: " << form.getSignGrade()
            << ", exec_grade: " << form.getExecGrade()
            << ", signed: " << (form.getIsSigned() ? "Yes" : "No");
    return oStream;
}