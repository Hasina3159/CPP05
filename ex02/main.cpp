/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:52:03 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/28 14:10:37 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    ShrubberyCreationForm shf("ShrubberyCreationForm 01");
    RobotomyRequestForm rbf("RobotomyRequestForm 01");
    PresidentialPardonForm prf("PresidentialPardonForm 01");
    Bureaucrat br("Petera", 5);

    //shf.execute(br);
    //rbf.beSigned(br);
    rbf.execute(br);
    //prf.execute(br);
    
    
    return 0;
}
