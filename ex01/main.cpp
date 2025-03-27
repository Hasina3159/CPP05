/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:52:03 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/27 15:42:29 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv; 

    try
    {
        Bureaucrat valid_bureaucrat("Alice", 50);
        std::cout << valid_bureaucrat << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;

    try
    {
        Bureaucrat low_grade_bureaucrat("Bob", 151);
        std::cout << low_grade_bureaucrat << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;

    try
    {
        Bureaucrat high_grade_bureaucrat("Charlie", 0);
        std::cout << high_grade_bureaucrat << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;

    try
    {
        Form valid_form("Form A", 50, 25);
        std::cout << valid_form << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;

    try
    {
        Form low_grade_form("Form B", 151, 25);
        std::cout << low_grade_form << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;

    try
    {
        Form high_grade_form("Form C", 1, 25);
        std::cout << high_grade_form << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------------------------------" << std::endl;
    
    try
    {
        Bureaucrat ko_bureaucrat("Alice", 50);
        Form ko_form("Form C", 1, 25);
        std::cout << ko_form << std::endl;

        ko_bureaucrat.signForm(ko_form);
        ko_form.beSigned(ko_bureaucrat);

        std::cout << ko_form << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;

    try
    {
        Bureaucrat ok_bureaucrat("Alice", 50);
        Form ok_form("Form C", 100, 25);
        std::cout << ok_form << std::endl;

        ok_bureaucrat.signForm(ok_form);
        ok_form.beSigned(ok_bureaucrat);

        std::cout << ok_form << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    return 0;
}
