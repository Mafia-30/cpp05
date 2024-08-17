/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:58:49 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/17 06:06:36 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat B1("B1", 150);

		Form F1("F1", 150, 10);
		
		B1.signForm(F1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}