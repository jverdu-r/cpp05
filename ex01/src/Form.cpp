/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:01:35 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/05 18:25:42 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(void) : _signed(false), _signGrade(1), _execGrade(1){}

Form::~Form(void){}

Form::Form(std::string str, int signGrade, int execGrade) : _name(str), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooLowException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& origin) : _name(origin.getName()), _signed(origin.getSigned()), _signGrade(origin.getSignGrade()), _execGrade(origin.getExecGrade())
{
    return;
}

Form &Form::operator=(const Form &origin)
{
    if (this == &origin) //i used this cuase you cannot do deep copy of constant attributes
        return(*this);
    return (*this);
}

int Form::getSignGrade(void) const
{
    return (this->_signGrade);
}

int Form::getExecGrade(void) const
{
    return (this->_execGrade);
}

std::string Form::getName(void) const
{
    return (this->_name);
}

bool Form::getSigned(void) const
{

    return (this->_signed);

}

void Form::beSigned(const Bureaucrat &bureu)
{
    if (bureu.getGrade() < this->_signGrade)
        throw Form::GradeTooLowException();
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