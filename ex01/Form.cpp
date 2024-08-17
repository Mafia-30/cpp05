/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 03:50:28 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/17 05:53:17 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Form Exceptions constructors

Form::GradeTooHighException::GradeTooHighException( std::string message ) : invalid_argument(message) {}

Form::GradeTooLowException::GradeTooLowException( std::string message ) : invalid_argument(message) {}

Form::GradeOutOfRange::GradeOutOfRange( std::string message ) : invalid_argument(message) {}


// Form constructors

Form::Form( std::string name, int sign_grade, int exec_grade )
	try
	: name(name), is_signed(false), req_sign_grade(validate_grade(sign_grade)), req_execute_grade(validate_grade(exec_grade))
	{
		std::cout << "Form: " << name << " has been created successfully!" << std::endl;
	}
	catch ( const std::exception& e )
	{
		throw ;
	}

Form::Form( const Form& ref )
	: name(ref.name), is_signed(ref.is_signed), req_sign_grade(ref.req_execute_grade), req_execute_grade(ref.req_execute_grade) {}


// Form copy assignment operator overload

Form &Form::operator = ( const Form& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	this->is_signed = rhs.is_signed;
	return (*this);
}


// Form destructor

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}


// Form methods

void	Form::beSigned( const Bureaucrat& B )
{
	if (this->is_signed)
	{
		std::cout << "Form already signed!" << std::endl;
		return;
	}

	if (B.getGrade() > this->req_sign_grade)
		throw Form::GradeTooLowException(get_reason(B));

	this->is_signed = true;
}

std::string	Form::get_reason( const Bureaucrat& B )
{
	std::ostringstream strm;

	strm << "Bureaucrat: " << B.getName() << " couldn’t sign " << this->name << " because grade " << B.getGrade() << " is lower than grade " << this->req_sign_grade << ".";

	return (strm.str()); 
}

std::string	Form::getName( void )
{
	return (this->name);
}

int	Form::getSignGrade( void )
{
	return (this->req_sign_grade);
}

int	Form::getExecuteGrade( void )
{
	return (this->req_execute_grade);
}

bool Form::isSigned( void )
{
	return (this->is_signed);
}

int	Form::validate_grade( int grade )
{
	if (grade < 1 || grade > 150)
		throw Form::GradeOutOfRange("Form construction error! Reason: A grade can only be within the range of 1 - 150!");
	return (grade);
}