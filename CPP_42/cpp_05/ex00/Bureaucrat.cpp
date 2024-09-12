#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    // name is const, so it cannot be assigned
    // this->name = other.name;
    // this->grade = other.grade;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // name is const, so it cannot be assigned
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->grade = grade;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Modifiers (increment and decrement grade verify if the increment and decrement are right "?")
void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException();
    }
    grade++;
}

// Exception classes
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Overloaded output operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}