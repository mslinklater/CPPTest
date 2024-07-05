//
//  main.cpp
//  MainCPPTest
//
//  Created by Martin Linklater on 24/06/2024.
//

#include <iostream>

#include "lambdas.hpp"
#include "multimap.hpp"
#include "smartpointer.hpp"
#include "vector.hpp"

#include "utils.hpp"

void LaunchSection(const std::string& section)
{    
}

void PromptForSection()
{
}

std::string CPPVersionToString(int version)
{
    switch(version)
    {
        case 202002:
            return "C++20";
        case 201703:
            return "C++17";
        case 201402:
            return "C++14";
        case 201103:
            return "C++11";
        case 199711:
            return "C++98";
        default:
            return "UNKNOWN";
    }
}

int main(int argc, const char * argv[]) {
//    std::cout << "=== Welcome to CPPTest ===\n";
    Utils::Title("Welcome to CPPTest");
    std::cout << "C++ release used to compile:" << CPPVersionToString(__cplusplus) << std::endl;
    std::cout << "\n";
    
    Lambdas::basics();
//    SmartPointer::unique_ptr();
//    SmartPointer::weak_ptr();
    
    return 0;
}
