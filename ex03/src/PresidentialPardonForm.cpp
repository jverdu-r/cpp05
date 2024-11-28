/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:56:33 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/28 17:01:37 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = "none";
}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &origin): AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = origin._target;
}

std::string PresidentialPardonForm::getTarget(void)
{
    if (this->_target.empty())
        return (NULL);
    else
        return(this->_target);
}

void PresidentialPardonForm::action(void) const
{
    std::cout <<"\033[32m" << this->_target << " has been pardoned by Zaphod Beeblebrox" << "\033[0m" << std::endl;
}