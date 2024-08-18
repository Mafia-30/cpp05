/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:27:31 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/17 11:26:09 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string name, std::string target ) : AForm(name, 145, 137, target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& ref ) : AForm(ref)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator = ( const ShrubberyCreationForm& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	AForm::operator=(rhs);
	return (*this);
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	std::ofstream targetFile;

	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException(executor.getName() + "'s grade is too low to execute " + this->getName()));

	targetFile.open(this->getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (!targetFile.is_open())
		throw std::runtime_error("Failed to open the file " + this->getTarget() + "_shrubbery!");
	
	targetFile <<	"				,@@@@@@@," << "\n";
	targetFile <<	"	,,,.   ,@@@@@@/@@,  .oo8888o" << "\n";
	targetFile <<	"	,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << "\n";
	targetFile <<	",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << "\n";
	targetFile <<	"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << "\n";
	targetFile <<	"%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << "\n";
	targetFile <<	"`&%\\ ` /%&'    |.|        \\ '|8'" << "\n";
	targetFile <<	"	|o|        | |         | |" << "\n";
	targetFile <<	"	|.|        | |         | |" << "\n";
	targetFile <<	"jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << "\n";
	
	targetFile.close();
}