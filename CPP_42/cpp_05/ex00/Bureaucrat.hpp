#pragma once
#include <iostream>
// #include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Orthodox Canonical Form constructor, copy constructor, destructor, assignment operator
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat(const std::string& name, int grade);
    //getter
    const std::string& getName() const;
    int getGrade() const;
    // modifiers
    void incrementGrade();
    void decrementGrade();
    //exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};
//Overloaded output operator to print the details of a Bureaucrat object
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);