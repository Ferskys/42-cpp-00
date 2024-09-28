#pragma once

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const& that);
		~PresidentialPardonForm(void);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& that);

		void	execute(Bureaucrat const& executor) const;
};

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm const& form);