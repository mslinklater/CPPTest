//
//  smartpointer.cpp
//  MainCPPTest
//
//  Created by Martin Linklater on 25/06/2024.
//

#include "smartpointer.hpp"
#include <iostream>
#include <memory>

void Observe(const std::weak_ptr<int>& wp)
{
    std::cout << "ptr.use_count() == " << wp.use_count() << "; ";
    if(std::shared_ptr<int> sp = wp.lock())
    {
        std::cout << "*wp = " << *sp << "\n";
    }
    else
    {
        std::cout << "wp is expired\n";
    }
}

void SmartPointer::unique_ptr()
{
    std::cout << "TODO - unique_ptr\n";
}

void SmartPointer::weak_ptr()
{
    std::cout << "C++11 --- weak_ptr ---\n";
    
    {
        std::weak_ptr<int> wp;
        
        {
            auto sp = std::make_shared<int>(42);
            wp = sp;
            Observe(wp);
        }
        Observe(wp);
    }
}
