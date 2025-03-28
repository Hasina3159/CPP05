/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:31:23 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/28 14:02:20 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

bool AForm::checkExecRequirements(const Bureaucrat &executor) const
{
    if (m_signed == false)
        throw FormNotSigned();
    else if (m_grade_for_exec < executor.getGrade())
    {
        std::cout << "needed : " << m_grade_for_exec << "; what executor have : " << executor.getGrade() << std::endl; 
        throw GradeTooLowException();
    }
    return (true);
}

AForm::AForm() : m_name(""), m_signed(false), m_grade_for_sign(0), m_grade_for_exec(0)
{
}

AForm::AForm(const std::string &name, const int &grade_for_sign, const int &grade_for_exec) : m_name(name), m_signed(false), m_grade_for_sign(grade_for_sign), m_grade_for_exec(grade_for_exec)
{
    if (grade_for_sign < 1 || grade_for_exec < 1)
        throw AForm::GradeTooHighException();
    else if (grade_for_sign > 150 || grade_for_exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : m_name(other.m_name), m_signed(other.m_signed), m_grade_for_sign(other.m_grade_for_sign), m_grade_for_exec(other.m_grade_for_exec)
{
    if (m_grade_for_sign < 1 || m_grade_for_exec < 1)
        throw AForm::GradeTooHighException();
    else if (m_grade_for_sign > 150 || m_grade_for_exec > 150)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        m_signed = other.m_signed;

    if (m_grade_for_sign < 1 || m_grade_for_exec < 1)
        throw AForm::GradeTooHighException();
    else if (m_grade_for_sign > 150 || m_grade_for_exec > 150)
        throw AForm::GradeTooLowException();
    return (*this);
}

bool AForm::isSigned() const
{
    return (m_signed);
}

unsigned int AForm::getGradeForSign() const
{
    return (m_grade_for_sign);
}

unsigned int AForm::getGradeForExec() const
{
    return (m_grade_for_exec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > m_grade_for_sign)
        throw AForm::GradeTooLowException();
    m_signed = true;
}

std::string AForm::getName() const
{
    return std::string(m_name.c_str());
}

AForm::~AForm()
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Form Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Form Grade is too low");
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("Form must be signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Signed : " << (form.isSigned() ? "Yes" : "No") << ", Grade required (sign): " << form.getGradeForSign() << ", Grade required (execute) : " << form.getGradeForExec();
    return (out);
}

