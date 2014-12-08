#include "Command.hpp"

void create(const std::string& username, const std::string& password, HashMap& storage)
{

	if (storage.contains(username))
		std::cout << "EXISTS" << std::endl;
	else
	{
		storage.add(username, password);
		std::cout << "CREATED" << std::endl;
	}
	
}

void login(const std::string& username, const std::string& password, const HashMap& storage)
{

	if (storage.contains(username) && storage.value(username) == password)
		std::cout << "SUCCEEDED" << std::endl;
	else
		std::cout << "FAILED" << std::endl;

}



void remove(const std::string& username, HashMap& storage)
{
	if (storage.contains(username))
	{
		storage.remove(username);
		std::cout << "REMOVED" << std::endl;
	}
	else
		std::cout << "NONEXISTENT" << std::endl;
}


