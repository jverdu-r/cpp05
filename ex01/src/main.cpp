/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:13:42 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/05 20:19:54 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

int main(void)
{
    {
        std::cout << "\033[1;33m Bureau could sign\033[0m" << std::endl;
        Bureaucrat  bureau("Hermes", 36);
        Form    form("Receipt", 35, 35);
        try
        {
            std::cout << form << std::endl;
            bureau.signForm(form);
            std::cout << form << std::endl;
        }
        catch (Form::GradeTooLowException &e)
        {  
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
        catch (Form::GradeTooHighException &e)
        {
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
    }
    {
        std::cout << "\033[1;33m Bureau couldn't sign\033[0m" << std::endl;
        Bureaucrat  bureau("Bender", 36);
        Form    form("Receipt", 37, 35);
        try
        {
            std::cout << form << std::endl;
            bureau.signForm(form);
            std::cout << form << std::endl;
        }
        catch (Form::GradeTooLowException &e)
        {  
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
        catch (Form::GradeTooHighException &e)
        {
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
    }
    {
        std::cout << "\033[1;33m Too high form\033[0m" << std::endl;
        try
        {
            Form form("Receipt", 151, 151);
            std::cout << form << std::endl;
        }
        catch (Form::GradeTooLowException &e)
        {  
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
        catch (Form::GradeTooHighException &e)
        {
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
    }
    {
        std::cout << "\033[1;33m Too low form\033[0m" << std::endl;
        try
        {
            Form form("Receipt", -1, -1);
            std::cout << form << std::endl;
        }
        catch (Form::GradeTooLowException &e)
        {  
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
        catch (Form::GradeTooHighException &e)
        {
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
    }
    return (0);
}