/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:01:35 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/05 18:25:42 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(void) : _signed(false), _signGrade(1), _execGrade(1){}

AForm::~AForm(void){}

AForm::AForm(std::string str, int signGrade, int execGrade) : _name(str), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooLowException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& origin) : _name(origin.getName()), _signed(origin.getSigned()), _signGrade(origin.getSignGrade()), _execGrade(origin.getExecGrade())
{
    return;
}

AForm &AForm::operator=(const AForm &origin)
{
    if (this == &origin) //i used this cuase you cannot do deep copy of constant attributes
        return(*this);
    return (*this);
}

int AForm::getSignGrade(void) const
{
    return (this->_signGrade);
}

int AForm::getExecGrade(void) const
{
    return (this->_execGrade);
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getSigned(void) const
{

    return (this->_signed);

}

void AForm::beSigned(const Bureaucrat &bureu)
{
    if (bureu.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor)
{
    if (executor.getGrade() > this->_execGrade)
        throw AForm::GradeTooLowException();
    if (!this->getSigned())
    {
        std::cout << "\033[33m" << "couldn't execute form because it's not signed" << "\033[0m" << std::endl;
        return ;
    }
    this->action();
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

void AForm::action(void) const{}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("the grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("the grade is too low");
}

std::ostream &operator<<(std::ostream& os, const AForm &form)
{
    os << "form: " << form.getName() << std::endl;
    os << "grade to sign: " << form.getSignGrade() << std::endl;
    os << "grade to execute " << form.getExecGrade() << std::endl;
    os << "status: " << form.getSigned() << std::endl;
    return (os);
}