/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:58:10 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/05 20:16:17 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = "none";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &origin): AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = origin._target;
}

std::string ShrubberyCreationForm::getTarget(void)
{
    return(this->_target);
}

void ShrubberyCreationForm::action(void) const
{
    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "\033[33m" << "can't open/create " << this->_target + "_shrubbery" << "\033[0m" << std::endl;
        return;
    }
    outfile <<
    "            # #### ####\n"
    "        ### \\/#|### |/####\n"
    "        ##\\/#/ \\||/##/_/##/_#\n"
    "       ###  \\/###|/ \\/ # ###\n"
    "    ##_\\_#\\_\\## | #/###_/_####\n"
    "    ## #### # \\ #| /  #### ##/##\n"
    "    __#_--###`  |{,###---###-~\n"
    "                \\ }{\n"
    "                }}{\n"
    "                }}{\n"
    "        akarafi {{}\n"
    "        , -=-~{ .-^- _\n"
    "                `}\n"
    "                 {"
    << std::endl;
}

