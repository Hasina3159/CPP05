/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:33:28 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/15 13:48:57 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Bureaucrat
{
private:
    const           std::string m_name;
    unsigned int    m_grade;
public:
    Bureaucrat ();
    Bureaucrat (const std::string &name, const int &grade);
    Bureaucrat (const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat ();
};
