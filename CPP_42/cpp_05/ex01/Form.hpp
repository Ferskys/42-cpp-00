#pragma once
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    // Orthodox Canonical Form
    Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    Form(const std::string& name, int signGrade, int execGrade);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);