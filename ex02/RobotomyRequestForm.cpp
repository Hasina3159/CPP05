/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:24:10 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/28 14:07:18 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <ctime>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm(name, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), 72, 45)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)  const
{    
    checkExecRequirements(executor);

    srand(std::time(NULL));
    int rnd = std::rand();
    if (rnd % 2 == 1)
        std::cout << "*Making some drilling noises*, " << executor.getName() << " has been robotomized successfully 50% of the time."  << std::endl;
    else
        std::cout << "Robotomy failed!" << std::endl;
}
