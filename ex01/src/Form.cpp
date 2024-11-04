/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:01:35 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/04 19:49:42 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(void){}

Form::~Form(void){}

Form::Form(std::string str, int signGrade, int execGrade)
{
    if (signGrade < 1)
        throw Form::GradeTooLowException();
    if (signGrade > 150)
        throw Form::GradeTooHighException();
    if (execGrade < 1)
        throw Form::GradeTooLowException():
    if (execGrade > 150)
        throw Form::GradeTooHighException();
    this->_name = str;
    this->_signGrade = signGrade;
    this->_execGrade = execGrade;
    this->_signed = false;
}

Form::Form(const Form& origin)
{
    *this = origin;
}

Form &Form::operator=(const Form &origin)
{
    this->_name = origin._name;
    this->_signGrade = origin._signGrade;
    this->_execGrade = origin._execGrade;
    this->_signed = false;
    return (*this);
}

int Form::getSignGrade(void) const
{
    return (this->_signGrade);
}

int Form::getExecGrade(void) const
{
    return (this->_execGrade)
}

std::string Form::getName(void) const
{
    return (this->_name);
}

std::string Form::getSigned(void) const
{
    if (this->_signed == true)
        return ("the form is signed");
    else
        return ("the form is not signed");
}

void Form::beSigned(Bureaucrat const &bureu)
{
    if (bureu.getGrade() < this->_signGrade)
        throw Form::GradeTooLowException():
    this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("the grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("the grade is too low");
}

std::ostream &operator<<(std::ostream& os, const Form &form)
{
    os << "form: " << form.getName() << std::endl;
    os << "grade to sign: " << form.getSignGrade() << std::endl;
    os << "grade to execute " << form.getExecGrade() << std::endl;
    os << "status: " << form.getSigned() << std::endl;
    return (os);
}