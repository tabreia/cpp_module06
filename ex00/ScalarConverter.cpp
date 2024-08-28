/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:14:22 by tabreia-          #+#    #+#             */
/*   Updated: 2023/10/03 17:14:22 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
	(void)copy;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter deconstructor called" << std::endl;
}

bool isChar(char c)
{
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 126))
		return (true);
	else
		return (false);
}

bool isInt(std::string &literal)
{
	if (literal[0] == '-')
	{
		for (int i = 1; i < (int)literal.length(); ++i)
		{
			if (literal[i] < 48 || literal[i] > 57)
				return (false);
		}
	}
	else
	{
		for (int i = 0; i < (int)literal.length(); ++i)
		{
			if (literal[i] < 48 || literal[i] > 57)
				return (false);
		}
	}
	return (true);
}

bool isFloat(std::string &literal)
{
	int	count = 0;
	int index = 0;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if(literal[literal.length() - 1] != 'f')
		return (false);
	for (int i = 0; i < (int)literal.length(); ++i)
	{
		if (literal[i] == '.')
		{
			count++;
			index = i;
		}
		if (count > 1)
			return (false);
	}
	if (count == 0)
		return (false);
	if (literal[0] == '-')
	{
		for (int i = 1; i < (int)literal.length() - 1; ++i)
		{
			if (i != index)
			{
				if (literal[i] < 48 || literal[i] > 57)
					return (false);
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)literal.length() - 1; ++i)
		{
			if (i != index)
			{
				if (literal[i] < 48 || literal[i] > 57)
					return (false);
			}
		}
	}
	return (true);
}

bool isDouble(std::string &literal)
{
	int count = 0;
	int index = 0;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	for (int i = 0; i < (int)literal.length(); ++i)
	{
		if (literal[i] == '.')
		{
			count++;
			index = i;
		}
		if (count > 1)
			return (false);
	}
	if (literal[0] == '-')
	{
		for (int i = 1; i < (int)literal.length(); ++i)
		{
			if (i != index)
			{
				if (literal[i] < 48 || literal[i] > 57)
					return (false);
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)literal.length(); ++i)
		{
			if (i != index)
			{
				if (literal[i] < 48 || literal[i] > 57)
					return (false);
			}
		}
	}
	return (true);
}

int identifyType(std::string &literal)
{
	std::stringstream ss(literal);
	if (literal.length() == 1)
	{
		if (isChar(literal[0]))
			return (1);
	}
	if (isInt(literal))
	{
		int conv;
		ss >> conv;
		return (2);
	}
	if (isFloat(literal))
		return (3);
	if (isDouble(literal))
		return (4);
	return (-1);
}

bool checkInf(std::string &literal, int type)
{
	switch (type)
	{
		case 3:
			if (literal == "-inff" || literal == "+inff" || literal == "nanf")
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << literal << std::endl;
				std::cout << "double: " << literal.erase(literal.length() - 1) << std::endl;
				return (true);
			}
			return (false);
		case 4:
			if (literal == "-inf" || literal == "+inf" || literal == "nan")
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << literal.append("f") << std::endl;
				std::cout << "double: " << literal.erase(literal.length() - 1)<< std::endl;
				return (true);
			}
			return (false);
	}
	return (false);
}

void printValues(int convInt, char convChar, double convDouble, float convFloat, int type, std::string &literal)
{
	switch (type)
	{
		case 1:
			convInt = static_cast<int>(convChar);
			convFloat = static_cast<float>(convChar);
			convDouble = static_cast<double>(convChar);
			std::cout << "char: " << convChar << std::endl;
			std::cout << "int: " << convInt << std::endl;
			std::cout << "float: " << convFloat << ".0f" << std::endl;
			std::cout << "double: " << convDouble << ".0" << std::endl;
			break;
		case 2:
			convChar = static_cast<char>(convInt);
			convFloat = static_cast<float>(convInt);
			convDouble = static_cast<double>(convInt);
			if (convInt >= 32 && convInt <= 126)
				std::cout << "char: " << convChar << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			if (convInt >= std::numeric_limits<int>::max() || convInt <= std::numeric_limits<int>::min())
				std::cout << "int: Out of data type range" << std::endl;
			else
				std::cout << "int: " << convInt << std::endl;
			std::cout << "float: " << convFloat << ".0f" << std::endl;
			std::cout << "double: " << convDouble << ".0" << std::endl;
			break;
		case 3:
			convChar = static_cast<char>(convFloat);
			convInt = static_cast<int>(convFloat);
			convDouble = static_cast<double >(convFloat);
			if (checkInf(literal, type))
				break;
			if (convInt >= 32 && convInt <= 126)
				std::cout << "char: " << convChar << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			if (convInt >= std::numeric_limits<int>::max() || convInt <= std::numeric_limits<int>::min())
				std::cout << "int: Out of data type range" << std::endl;
			else
				std::cout << "int: " << convInt << std::endl;
			if (convDouble - convInt == 0)
			{
				if (convFloat >= std::numeric_limits<float>::max() || convFloat <= std::numeric_limits<float>::min())
					std::cout << "float: Out of data type range" << std::endl;
				else
					std::cout << "float: " << convFloat << ".0f" << std::endl;
				if (convDouble >= std::numeric_limits<double>::max() || convDouble <= std::numeric_limits<double>::min())
					std::cout << "double: Out of data type range" << std::endl;
				else
					std::cout << "double: " << convDouble << ".0" << std::endl;
			}
			else
			{
				if (convFloat >= std::numeric_limits<float>::max() || convFloat <= std::numeric_limits<float>::min())
					std::cout << "float: Out of data type range" << std::endl;
				else
					std::cout << "float: " << convFloat << "f" << std::endl;
				if (convDouble >= std::numeric_limits<double>::max() || convDouble <= std::numeric_limits<double>::min())
					std::cout << "double: Out of data type range" << std::endl;
				else
					std::cout << "double: " << convDouble << std::endl;
			}

			break;
		case 4:

			convChar = static_cast<char>(convDouble);
			convInt = static_cast<int>(convDouble);
			convFloat = static_cast<float>(convDouble);
			if (checkInf(literal, type))
				break;
			if (convInt >= 32 && convInt <= 126)
				std::cout << "char: " << convChar << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			if (convInt >= std::numeric_limits<int>::max())
				std::cout << "int: Over int max" << std::endl;
			else
				std::cout << "int: " << convInt << std::endl;
			if (convDouble - convInt == 0)
			{
				if (convFloat >= std::numeric_limits<float>::max() || convFloat <= std::numeric_limits<float>::min())
					std::cout << "float: Over float max" << std::endl;
				else
					std::cout << "float: " << convFloat << ".0f" << std::endl;
				if (convDouble >= std::numeric_limits<double>::max() || convDouble <= std::numeric_limits<double>::min())
					std::cout << "double: Over double max" << std::endl;
				else
					std::cout << "double: " << convDouble << ".0" << std::endl;
			}
			else
			{
				if (convFloat >= std::numeric_limits<float>::max() || convFloat <= std::numeric_limits<float>::min())
					std::cout << "float: Over float max" << std::endl;
				else
					std::cout << "float: " << convFloat << "f" << std::endl;
				if (convDouble >= std::numeric_limits<double>::max() || convDouble <= std::numeric_limits<double>::min())
					std::cout << "double: Over double max" << std::endl;
				else
					std::cout << "double: " << convDouble << std::endl;
			}
			break;
	}
}

void ScalarConverter::convert(std::string literal)
{
	int		type;
	int		convInt = 0;
	char	convChar = '\0';
	double	convDouble = 0.0;
	float	convFloat = 0.0;

	std::stringstream ss(literal);

	type = identifyType(literal);
	switch (type)
	{
		case 1:
			ss >> convChar;
			printValues(convInt, convChar, convDouble, convFloat, type, literal);
			break;
		case 2:
			ss >> convInt;
			printValues(convInt, convChar, convDouble, convFloat, type, literal);
			break;
		case 3:
			ss >> convFloat;
			printValues(convInt, convChar, convDouble, convFloat, type, literal);
			break;
		case 4:
			ss >> convDouble;
			printValues(convInt, convChar, convDouble, convFloat, type, literal);
			break;
		default:
			std::cout << "Data type not supported" << std::endl;
	}

}