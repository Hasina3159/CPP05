/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:31:23 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/27 15:28:53 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : m_name(""), m_signed(false), m_grade_for_sign(0), m_grade_for_exec(0)
{
}

Form::Form(const std::string &name, const int &grade_for_sign, const int &grade_for_exec) : m_name(name), m_signed(false), m_grade_for_sign(grade_for_sign), m_grade_for_exec(grade_for_exec)
{
    if (grade_for_sign < 1 || grade_for_exec < 1)
        throw Form::GradeTooHighException();
    else if (grade_for_sign > 150 || grade_for_exec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : m_name(other.m_name), m_signed(other.m_signed), m_grade_for_sign(other.m_grade_for_sign), m_grade_for_exec(other.m_grade_for_exec)
{
    if (m_grade_for_sign < 1 || m_grade_for_exec < 1)
        throw Form::GradeTooHighException();
    else if (m_grade_for_sign > 150 || m_grade_for_exec > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        m_signed = other.m_signed;

    if (m_grade_for_sign < 1 || m_grade_for_exec < 1)
        throw Form::GradeTooHighException();
    else if (m_grade_for_sign > 150 || m_grade_for_exec > 150)
        throw Form::GradeTooLowException();
    return (*this);
}

bool Form::isSigned() const
{
    return (m_signed);
}

int Form::getGradeForSign() const
{
    return (m_grade_for_sign);
}

int Form::getGradeForExec() const
{
    return (m_grade_for_exec);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > m_grade_for_sign)
        throw Form::GradeTooLowException();
    m_signed = true;
}

std::string Form::getName() const
{
    return std::string(m_name.c_str());
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade is too low");
}


std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Signed : " << (form.isSigned() ? "Yes" : "No") << ", Grade required (sign): " << form.getGradeForSign() << ", Grade required (execute) : " << form.getGradeForExec();
    return (out);
}