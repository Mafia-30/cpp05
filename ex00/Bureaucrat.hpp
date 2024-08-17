/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 05:03:30 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/17 00:49:02 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

class Bureaucrat {

public :

	// Static exception objects

	static std::invalid_argument	GradeTooHighException;
	static std::invalid_argument	GradeTooLowException;

	// Constructors

	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& ref );

	// Destructor

	~Bureaucrat();

	// Copy assignment operator overload

	Bureaucrat& operator=( const Bureaucrat& rhs );

	// Getters

	std::string	getName( void ) const;
	int			getGrade( void ) const;

	// Public member methods

	void	upGrade( void );
	void	downGrade( void );

private :

	int 				grade;	
	const std::string	name;

	static int	validateGrade( int grade );
	
};


#endif