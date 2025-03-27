/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:31:36 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/27 15:18:05 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	m_name;
	bool				m_signed;
	const unsigned int	m_grade_for_sign;
	const unsigned int	m_grade_for_exec;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

public:
	Form ();
	Form (const std::string &name, const int &grade_for_sign, const int &grade_for_exec);
	Form (const Form &other);
	~Form ();
	Form &operator=(const Form &other);
	bool isSigned() const;
	int getGradeForSign() const;
	int getGradeForExec() const;
	void beSigned(const Bureaucrat &bureaucrat);
	std::string getName() const;
};

template <typename T>
std::string to_string(const T& value)
{
	std::ostringstream os;
	os << value;
	return (std::string(os.str()));
}

std::ostream &operator<<(std::ostream &out, const Form &form);