/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:07:33 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/06 17:30:19 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat::Bureaucrat(std::string str, int grade) : _name(str)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
    std::cout << "Bureucrat " << this->_name << " was created with _grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin)
{
    *this = origin;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("the _grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("the _grade is too low");
}

std::string Bureaucrat::getName(void) const
{
    return(this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &origin)
{
    this->_grade = origin.getGrade();
    return(*this);
}

void Bureaucrat::increaseGrade(void)
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade++;
    std::cout << "bureaucrat " << this->getName() << " grade is now " << this->getGrade() << std::endl;
}

void Bureaucrat::decreaseGrade(void)
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooLowException();
    else
    {
        this->_grade--;
        std::cout << "bureaucrat " << this->getName() << " grade is now " << this->getGrade() << std::endl;
    }
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "\033[32m" << this->getName() << " signed form " << form.getName() << "\033[0m" << std::endl;

    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << "\033[31m" <<this->getName() << " couldn't sign form " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
    }
}

void Bureaucrat::executeForm(AForm &form) 
{
    try 
    {
        form.execute(*this);
        std::cout << "\033[32m" << this->getName() << " executed form " << form.getName() << "\033[0m" << std::endl;
    }
    catch (AForm::GradeTooLowException & e) 
    {
        std::cout << this->getName() << " couldn't execute "<< form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureu)
{
    os << bureu.getName() << " - who's _grade is " << bureu.getGrade();
    return (os);
}