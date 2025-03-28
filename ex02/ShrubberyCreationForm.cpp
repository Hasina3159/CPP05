/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:24:15 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/28 14:08:07 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : AForm(name, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), 145, 137)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)  const
{
    checkExecRequirements(executor);

    std::ofstream out(std::string(getName() + "_shrubbery").c_str());
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
