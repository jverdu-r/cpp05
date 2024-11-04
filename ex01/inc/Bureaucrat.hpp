/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:53:44 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/04 19:47:02 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(std::string str, int grade);
        Bureaucrat(const Bureaucrat& origin);
        Bureaucrat &operator=(const Bureaucrat &origin);
        std::string getName(void) const;
        int getGrade(void) const;
        void increaseGrade(void);
        void decreaseGrade(void);
        void signForm(Form &form);
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

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureu);
#endif
