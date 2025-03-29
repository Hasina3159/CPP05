#include "Intern.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:28:10 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/29 10:28:11 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <memory>

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target_name) const
{
	std::string str[FORM_COUNT] = {"shrubbery", "robotomy" , "presidential"};
	AForm       *all_form[FORM_COUNT] = {new ShrubberyCreationForm(target_name), new RobotomyRequestForm(target_name), new PresidentialPardonForm(target_name)};
	AForm		*ret = NULL;
	for (size_t i = 0; i < FORM_COUNT; i++)
	{
		if (form_name == std::string(str[i] + " request"))
			ret = all_form[i];
		else
			delete all_form[i];
	}
	if (ret == NULL)
	{
		std::cout << "Form requested does not exist." << std::endl;
		return (NULL);
	}
	return (ret);
}
