/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:01:07 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/28 13:41:26 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &name);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    virtual void execute(Bureaucrat const & executor)  const;
};