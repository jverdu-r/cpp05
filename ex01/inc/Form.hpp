/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:47:57 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/04 19:31:27 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool        _signed;
        const int _signGrade;
        const int _execGrade;
    public:
        Form(void);
        ~Form(void);
        Form(std::string str, int signGrade, int execGrade);
        Form(const Form& origin);
        Form &operator=(const Form &origin);
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        std::string getName(void) const;
        std::string getSigned(void) const;
        void beSigned(Bureaucrat const &bureu);
        class GradeTooHighException : std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& os, const Form &form);
#endif