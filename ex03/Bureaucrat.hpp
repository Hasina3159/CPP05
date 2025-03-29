/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:33:28 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/28 14:11:59 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string   m_name;
    unsigned int        m_grade;
protected:
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
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
	void signForm(AForm &form);
    void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);