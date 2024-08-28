/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <@student.42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:14:22 by tabreia-          #+#    #+#             */
/*   Updated: 2024/05/23 11:26:14 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
}