/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:47:57 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/05 20:06:21 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        const std::string _name;
        bool        _signed;
        const int _signGrade;
        const int _execGrade;
    public:
        AForm(void);
        virtual~AForm(void);
        AForm(std::string str, int signGrade, int execGrade);
        AForm(const AForm& origin);
        AForm &operator=(const AForm &origin);
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        std::string getName(void) const;
        bool getSigned(void) const;
        void beSigned(const Bureaucrat &bureu);
        void execute(const Bureaucrat &executor);
        virtual void action(void) const = 0;
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

std::ostream &operator<<(std::ostream& os, const AForm &form);
#endif