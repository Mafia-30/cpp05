/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:28:02 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/18 02:42:35 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include <exception>

class Intern{

public :

	Intern( void );

	~Intern();

	AForm	*makeForm( std::string name, std::string target );

private :

	int		MatchesRobotomyRequest( std::string name );
	int		MatchesShrubberyCreation( std::string name );
	int		MatchesPresidentialPardon( std::string name );

};


#endif