/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:11:32 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/06 18:58:12 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>

class AForm;

class Intern
{
    public:
        Intern(void);
        ~Intern(void);
        Intern(const Intern& origin);
        Intern &operator=(const Intern &origin);
        AForm *makeForm(std::string formName, std::string target);
};
#endif