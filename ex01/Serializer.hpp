#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string	s1;
	std::string	s2;
}				Data;

class Serializer
{
        Serializer();
		Serializer(const Serializer &src);

		~Serializer();

		Serializer &operator=(const Serializer &src);

	public:

		static uintptr_t serialize(Data *ptr);
		static Data *unserialize(uintptr_t raw);
};
