/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:59:45 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/04 18:44:27 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat bureu00("Hermes", 36);
        std::cout << bureu00 << std::endl;
        //std::cout << bureu00.getName() << " - who's grade is " << bureu00.getGrade() << std::endl;
        bureu00.decreaseGrade();
        bureu00.decreaseGrade();
        //std::cout << bureu00.getName() << " - who's grade is " << bureu00.getGrade() << std::endl;
        std::cout << bureu00 << std::endl;
        bureu00.increaseGrade();
        bureu00.increaseGrade();
        //std::cout << bureu00.getName() << " - who's grade is " << bureu00.getGrade() << std::endl;
        std::cout << bureu00 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureu01("Smithers", 150);
        bureu01.increaseGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureu02("Fray", 1);
        bureu02.decreaseGrade();
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}