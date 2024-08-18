/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:30:45 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/18 02:33:12 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {};

Intern::~Intern() {};

int		Intern::MatchesRobotomyRequest( std::string name )
{
	return (!name.compare("robotomy request") ? 1 : 0);
}

int		Intern::MatchesShrubberyCreation( std::string name )
{
	return (!name.compare("shrubbery creation") ? 2 : 0);
}

int		Intern::MatchesPresidentialPardon( std::string name )
{
	return (!name.compare("presidential pardon") ? 3 : 0);
}

AForm *Intern::CreateNewRobotomyRequest( std::string name, std::string target)
{
	try
	{
		AForm* f;

		f = new RobotomyRequestForm(name, target);
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return (f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

AForm *Intern::CreateNewShrubberyCreation( std::string name, std::string target)
{
	try
	{
		AForm* f;

		f = new ShrubberyCreationForm(name, target);
		std::cout << "Intern creates ShrubberyCreationForm"	<< std::endl;	
		return (f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

AForm *Intern::CreateNewPresidentialPardon( std::string name, std::string target)
{
	try
	{
		AForm* f;

		f = new PresidentialPardonForm(name, target);
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;	
		return (f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

AForm	*Intern::makeForm( std::string name, std::string target )
{
	int		key = 0;

	key += MatchesRobotomyRequest(name);
	key += MatchesShrubberyCreation(name);
	key += MatchesPresidentialPardon(name);

	std::cout << key << std::endl;

	switch (key)
	{
	case 1:
		return (CreateNewRobotomyRequest(name, target));
	case 2:
		return (CreateNewShrubberyCreation(name, target));
	case 3:
		return (CreateNewPresidentialPardon(name, target));
	default:
		std::cerr << "Unknown form type!" << std::endl;
		return (NULL);
	}
}