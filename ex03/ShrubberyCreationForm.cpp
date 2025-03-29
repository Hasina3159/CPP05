/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:24:15 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/29 11:49:37 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 145, 137), m_target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery", 145, 137), m_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("shrubbery", 145, 137), m_target(other.getTarget())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        setTarget(other.getTarget());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)  const
{
    checkExecRequirements(executor);

    std::ofstream out(std::string(getTarget() + "_shrubbery").c_str());
    out << "             v .   ._, |_  .,\n" 
    "           `-._\\/  .  \\ /    |/_\n"
    "               \\  _\\, y | \\//\n"
    "         _\\_.___\\, \\/ -.\\||\n"
    "           `7-,--.`._||  / / ,\n"
    "           /'     `-. `./ / |/_.'\n"
    "                     |    |//\n"
    "                     |_    /\n"
    "                     |-   |\n"
    "                     |   =|\n"
    "                     |    |\n"
    "--------------------/ ,  . \\--------._\n" << std::endl;
}

void ShrubberyCreationForm::setTarget(const std::string &target)
{
    m_target = target;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (m_target);
}
