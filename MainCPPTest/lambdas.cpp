//
//  lambdas.cpp
//  MainCPPTest
//
//  Created by Martin Linklater on 24/06/2024.
//

#include "lambdas.hpp"

#include <vector>
#include <iostream>
#include <functional>

#include "utils.hpp"

static void PrintFunc(int x)
{
    std::cout << x << '\n';
}

struct Printer
{
    void operator()(int x) const
    {
        std::cout << x << '\n';
    }
};

struct PrinterEx
{
    PrinterEx() : numCalls(0) {}
    
    void operator()(int x)
    {
        std::cout << x << "\n";
        ++numCalls;
    }
    int numCalls;
};

struct PrinterExCapture
{
    PrinterExCapture(std::string str)
    : numCalls(0)
    , strText(str)
    {}
    
    void operator()(int x)
    {
        std::cout << x << "\n";
        ++numCalls;
    }
    std::string strText;
    int numCalls;
};

void Lambdas::cpp98()
{
    Utils::Title("Lambda Features in C++98");
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    
    Utils::Section("PrintFunc");
    std::for_each(v.begin(), v.end(), PrintFunc);

    Utils::Section("struct Printer");
    std::for_each(v.begin(), v.end(), Printer());
    
    Utils::Section("struct PrinterEx");
    // An instance of the class parameter is used in the for_each and returned
    // Q - how is the allocation done ? Heap.
    const PrinterEx vis = std::for_each(v.begin(), v.end(), PrinterEx());
    std::cout << "num calls " << vis.numCalls << '\n';
    
    Utils::Section("struct PrinterEx - second instance");
    const PrinterEx vis2 = std::for_each(v.begin(), v.end(), PrinterEx());
    std::cout << "num calls " << vis2.numCalls << '\n';
    
    Utils::Section("struct PrinterExCapture");
    const PrinterExCapture vis3 = std::for_each(v.begin(), v.end(), PrinterExCapture("Elem: "));;
    std::cout << "num calls " << vis3.strText << vis3.numCalls << '\n';

    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        v.push_back(7);
        v.push_back(8);
        v.push_back(9);
        // only compiles prior to C++17
        // warning with C++11
    #if __cplusplus < 201703
        Utils::Section("bind2nd");
        const size_t smaller5 = std::count_if(v.begin(), v.end(), std::bind2nd(std::less<int>(), 5));
        std::cout << "smaller5 = " << smaller5 << std::endl;
    #endif
            
    #if __cplusplus >= 201103
        Utils::Section("bind");
        const size_t val = std::count_if(v.begin(), v.end(),
                                            std::bind(std::logical_and<bool>(),
                                            std::bind(std::greater<int>(), std::placeholders::_1, 2),
                                            std::bind(std::less_equal<int>(), std::placeholders::_1, 6)));
        std::cout << "x > 2 && x <= 6 = " << val << std::endl;
    #endif
    }
}

void Lambdas::cpp11()
{
    Utils::Title("Lambda Features in C++11");

}