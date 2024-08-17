/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 05:25:56 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/17 01:02:23 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Static exception objects construction

std::invalid_argument Bureaucrat::GradeTooHighException = std::invalid_argument("Grade is too high!");
std::invalid_argument Bureaucrat::GradeTooLowException = std::invalid_argument("Grade is too Low!");

Bureaucrat::Bureaucrat( std::string name, int grade )
	try
		: grade(Bureaucrat::validateGrade( grade )), name(name)
	{
		std::cout << "Bureaucrat " << this->name << " has been created successfully!" << std::endl;
	}
	catch(const std::exception& e)
	{
		throw ;
	}

Bureaucrat::Bureaucrat( const Bureaucrat& ref ) : grade(ref.grade), name(ref.name)
{
	std::cout << "Bureaucrat " << this->name << " has been created successfully!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	this->grade = rhs.grade;

	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed." << std::endl;
}

std::string Bureaucrat::getName( void ) const
{
	return (this->name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void	Bureaucrat::upGrade( void )
{
	if (this->grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException;

	this->grade--;
	std::cout << "Bureaucrat " << this->name << " has been up graded!" << std::endl;
}

void	Bureaucrat::downGrade( void )
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException;

	this->grade++;

	std::cout << "Bureaucrat " << this->name << " has been down graded!" << std::endl;
}

int	Bureaucrat::validateGrade( int grade )
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException;

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException;

	return (grade);
}