/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:24:10 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/29 11:53:04 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <ctime>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", 72, 45),  m_target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy", 72, 45),  m_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("robotomy", 72, 45),  m_target(other.getTarget())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        setTarget(other.getTarget());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{    
    checkExecRequirements(executor);

    srand(std::time(NULL));
    int rnd = std::rand();
    if (rnd % 2 == 1)
        std::cout << "*Making some drilling noises*, " << getTarget() << " has been robotomized successfully 50% of the time."  << std::endl;
    else
        std::cout << "Robotomy failed!" << std::endl;
}

void RobotomyRequestForm::setTarget(const std::string &target)
{
    m_target = target;
}

std::string RobotomyRequestForm::getTarget() const
{
    return (m_target);
}
