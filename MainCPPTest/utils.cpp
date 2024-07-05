#include "utils.hpp"

#include <iostream>

void Utils::Title(const std::string& str)
{
    std::cout << "=== " << str << " ===\n";
}

void Utils::Section(const std::string& str)
{
    std::cout << "--- " << str << " ---\n";
}
