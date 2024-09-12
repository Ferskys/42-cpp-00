#pragma once

# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const& that);
		~Intern(void);
		Intern&	operator=(Intern const& that);

		AForm*	makeForm(std::string const& formName,
			std::string const& target
		) const;
};