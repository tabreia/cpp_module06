/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:14:22 by tabreia-          #+#    #+#             */
/*   Updated: 2023/10/03 17:14:22 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

class ScalarConverter
{
		ScalarConverter();
		ScalarConverter(ScalarConverter &copy);
		ScalarConverter &operator=(ScalarConverter &copy);
	public:
		~ScalarConverter();

		static void convert(std::string literal);
};



#endif