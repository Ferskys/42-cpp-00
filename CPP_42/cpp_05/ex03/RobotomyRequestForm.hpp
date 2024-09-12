#pragma once

# include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const& that);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& that);

		void	execute(Bureaucrat const& executor) const
			throw(GradeTooLowException, NotSignedException,
				std::ios_base::failure
			);
};
