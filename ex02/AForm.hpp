/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:31:36 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/28 13:56:56 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	m_name;
	bool				m_signed;
	const unsigned int	m_grade_for_sign;
	const unsigned int	m_grade_for_exec;

protected:
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		virtual const char *what() const throw();
	};
	bool checkExecRequirements(const Bureaucrat &executor) const;
public:
	AForm ();
	AForm (const std::string &name, const int &grade_for_sign, const int &grade_for_exec);
	AForm (const AForm &other);
	virtual ~AForm ();
	AForm &operator=(const AForm &other);
	bool isSigned() const;
	unsigned int getGradeForSign() const;
	unsigned int getGradeForExec() const;
	void beSigned(const Bureaucrat &bureaucrat);
	std::string getName() const;
	virtual void execute(Bureaucrat const & executor)  const = 0;
	
};

std::ostream &operator<<(std::ostream &out, const AForm &form);