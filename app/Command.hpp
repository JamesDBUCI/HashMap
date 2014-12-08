#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include "HashMap.hpp"

void create(const std::string& username, const std::string& password, HashMap& storage);

void login(const std::string& username, const std::string& password, const HashMap& storage);

void remove(const std::string& username, HashMap& storage);



#endif // COMMAND_HPP