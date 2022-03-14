// Taylor Martin
// CS-210 
// RAII 
// "main.cpp"
#include "filehandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept> 
#include <iostream>

int main()
{

    FileHandler inFileHandler("text.txt","r");

    //catch and handle reading exceptions 
    try
    {
        inFileHandler.read_file(); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    char testString[] = "This is a test string. Written to a test file";
    FileHandler outFileHandler("testOut.txt","w"); 

    //catch and handle writing exceptions
    try
    {
        outFileHandler.write_file(testString); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
    return 0;
}