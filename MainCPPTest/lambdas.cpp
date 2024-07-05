//
//  lambdas.cpp
//  MainCPPTest
//
//  Created by Martin Linklater on 24/06/2024.
//

#include "lambdas.hpp"
#include <vector>
#include <iostream>

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

void Lambdas::basics()
{
    Utils::Title("Lambda Basics");
    
    {
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
    }
}
