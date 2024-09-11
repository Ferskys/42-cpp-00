#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    // Orthodox Canonical AForm
    AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    AForm(const std::string& name, int signGrade, int execGrade) throw(GradeTooHighException, GradeTooLowException);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(const Bureaucrat& bureaucrat) throw(GradeTooLowException);
    virtual void execute(const Bureaucrat& executor) const throw(GradeTooLowException, NotSignedException, std::ios_base::failure) = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class NotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);