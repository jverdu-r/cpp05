/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:13:24 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/06 19:29:22 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main(void)
{
    {
        std::cout <<"\033[1;33m" << "--Shrubbery test start--" << "\033[0m" <<std::endl;
        try 
        {
            Intern someRandomIntern;
            AForm *SCF;
            SCF = someRandomIntern.makeForm("shrubbery creation", "Bender");
            Bureaucrat b1("Bob", 136);
            Bureaucrat b2("Jhon", 145);
            b2.signForm(*SCF);
            b1.executeForm(*SCF);

            b2.executeForm(*SCF);
        }
	    catch (ShrubberyCreationForm::GradeTooHighException &e)
        {
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
        catch (ShrubberyCreationForm::GradeTooLowException &e)
        {
            std::cout << "\033[31m" <<  e.what() << "\033[0m" << std::endl;
        }
        std::string filename = "home_shrubbery";
        std::ifstream file(filename.c_str());
        std::string line;
        while (std::getline(file, line))
            std::cout << line << std::endl;
        file.close();
        std::cout <<"\033[1;33m" << "--Shrubbery test end--" << "\033[0m" <<std::endl;
    }
    {
        std::cout <<"\033[1;33m" << "--Robotomy test start--" << "\033[0m" <<std::endl;
        try 
        {
            Intern someRandomIntern;
            AForm *RRF;
            Bureaucrat b1("Bob", 43);
            Bureaucrat b2("Jhon", 71);
            RRF = someRandomIntern.makeForm("robotomy request", "home");
            b2.signForm(*RRF);
            b1.executeForm(*RRF);

            b2.executeForm(*RRF);
        }
	    catch (RobotomyRequestForm::GradeTooHighException &e)
        {
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
        catch (RobotomyRequestForm::GradeTooLowException &e)
        {
            std::cout << "\033[31m" <<  e.what() << "\033[0m" << std::endl;
        }
        std::cout <<"\033[1;33m" << "--Robotomy test end--" << "\033[0m" <<std::endl;
    }
    {
        std::cout <<"\033[1;33m" << "--Presidential pardon test start--" << "\033[0m" <<std::endl;
        try 
        {
            Intern someRandomIntern;
            AForm *PPF;
            Bureaucrat b1("Bob", 4);
            Bureaucrat b2("Jhon", 24);
            PPF = someRandomIntern.makeForm("robotomy request", "Bender");
            b2.signForm(*PPF);
            b1.executeForm(*PPF);

            b2.executeForm(*PPF);
        }
	    catch (PresidentialPardonForm::GradeTooHighException &e)
        {
            std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
        }
        catch (PresidentialPardonForm::GradeTooLowException &e)
        {
            std::cout << "\033[31m" <<  e.what() << "\033[0m" << std::endl;
        }
        std::cout <<"\033[1;33m" << "--Presidential pardon test end--" << "\033[0m" <<std::endl;
    }
    return (0);
}