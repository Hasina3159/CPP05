#include "Bureaucrat.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:33:59 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/15 13:34:00 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : m_name(name), m_grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : m_name(other.m_name), m_grade(other.m_grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return (*this);
    this->m_grade = other.m_grade;
    return (*this);
}

const std::string &Bureaucrat::getName() const
{
    return (this->m_name);
}

unsigned int Bureaucrat::getGrade() const
{
    return (this->m_grade);
}

void Bureaucrat::incrementGrade()
{
    this->m_grade--;
    if (this->m_grade < 1)
    {
        this->m_grade = 1;
        throw Bureaucrat::GradeTooHighException();
    }
}

void Bureaucrat::decrementGrade()
{
    this->m_grade++;
    if (this->m_grade > 150)
    {
        this->m_grade = 150;
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat()
{

}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << std::string(", bureaucrat grade ") << to_string(bureaucrat.getGrade()) << std::endl;
    return (out);
}
