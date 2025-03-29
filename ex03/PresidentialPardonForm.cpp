/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:24:04 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/29 11:55:57 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential", 25, 5), m_target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("presidential", 25, 5), m_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("presidential", 25, 5), m_target(other.getTarget())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        setTarget(other.getTarget());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)  const
{
    checkExecRequirements(executor);
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::setTarget(const std::string &target)
{
    m_target = target;
}

std::string PresidentialPardonForm::getTarget() const
{
    return (m_target);
}
