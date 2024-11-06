/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:16:51 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/06 19:03:26 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern(void){}

Intern::~Intern(void){}

Intern::Intern(const Intern& origin)
{
    (void)origin;
    return;
}

Intern &Intern::operator=(const Intern &origin)
{
    if (this == &origin)
        return(*this);
    return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    /*std::map<std::string, void (*::*)()> forms;
    forms["shubbery creation"] = &ShrubberyCreationForm form(target);
    forms["robotomy request"] = &RobotomyRequestForm form(target);
    forms["presidential pardon"] = &PresidentialPardonForm form(target);

    if (forms.find(formName) == forms.end())
        std::cout << "\033[31m" << formName << " form not found" << "\033[0m" << std::endl;
    std::cout << form << std::endl;*/

    std::string forms[] = {"shubbery creation", "robotomy request", "presidential pardon"};
    int index = -1;
    AForm *form = NULL;
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            index = i;
            std::cout << "\033[33m" << "Intern creates " << forms[index] << "\033[0m" << std::endl;
            break;
        }
    }

    switch (index)
    {
        case 0: 
                form = new ShrubberyCreationForm(target);
                break;
        case 1: 
                form = new RobotomyRequestForm(target);
                break;
        case 2: 
                form = new PresidentialPardonForm(target);
                break;
        default:
                std::cout << "\033[31m" << formName << " not found and cannot create it" << "\033[0m" << std::endl;
                return(NULL);
    }
    return(form);
}