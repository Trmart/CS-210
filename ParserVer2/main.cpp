#include "parser.h" 

int main(int argc, char* argv[])
{
    string inFile = argv[1]; 

    Parser parser; 

    parser.parse(inFile); 

    return 0; 
}