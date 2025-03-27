/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:33:28 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/27 15:17:28 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
    const std::string   m_name;
    unsigned int        m_grade;
public:
    Bureaucrat ();
    Bureaucrat (const std::string &name, const int &grade);
    Bureaucrat (const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat ();
    const std::string &getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrementGrade();
	void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);