/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:58:49 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/19 02:04:50 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat B1("B1", 1);
		Intern I1;
		AForm* F1 = I1.makeForm("robotodmy request", "Target");
		
		B1.signForm(*F1);
		B1.executeForm(*F1);

			Bureaucrat B1("B1", 0);
		
		
		delete F1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}