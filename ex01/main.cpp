#include "Serializer.hpp"

int	main(void)
{
	Data*	Data1 = new Data;
	uintptr_t	serializerData1;

	std::cout << "--- Data1 address before serialization ---" << std::endl;
	std::cout << "Address: " << Data1 << std::endl;

	serializerData1 = Serializer::serialize(Data1);
	Data1 = Serializer::unserialize(serializerData1);

	std::cout << "--- Data1 address after serialization ---" << std::endl;
	std::cout << "Address: " << Data1 << std::endl;

	return (0);
}