/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:22:51 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/28 17:00:52 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = "none";
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &origin): AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = origin._target;
}

std::string RobotomyRequestForm::getTarget(void)
{
    if (this->_target.empty())
        return (NULL);
    else
        return(this->_target);
}

void RobotomyRequestForm::action(void) const
{
    std::srand(std::time(0));
    int roboLuck = std::rand() % 2;
    if (roboLuck > 0)
        std::cout << "\033[32m" << this->_target << " has been robotomized" <<  "\033[0m" << std::endl;
    else
        std::cout << "\033[33m" << this->_target << " hasn't been robotomized" <<  "\033[0m" << std::endl;
}