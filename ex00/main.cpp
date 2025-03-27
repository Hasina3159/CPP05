/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:52:03 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/15 13:53:09 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv; 
    Bureaucrat bureaucrat("John", 150);
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade();
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade();
    bureaucrat.decrementGrade();
    std::cout << bureaucrat << std::endl;
    return (0);
}
