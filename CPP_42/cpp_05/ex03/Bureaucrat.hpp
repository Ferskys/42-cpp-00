#pragma once
#include <iostream>
// #include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat(const std::string& name, int grade);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form);
    void executeForm(const AForm& form);

    // Exception Classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

// Output operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
