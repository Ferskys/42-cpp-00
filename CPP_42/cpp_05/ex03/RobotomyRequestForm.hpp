#pragma once

# include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const& that);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& that);

		void	execute(Bureaucrat const& executor) const;
};

std::ostream&	operator<<(std::ostream& os, RobotomyRequestForm const& form);