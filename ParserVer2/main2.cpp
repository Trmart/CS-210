#include "token.h"

int main(int argc, char *argv[])
{
    Tokenizer tokenizer; 
    string inFile = argv[1]; 
    ifstream in(inFile); 
    
    if(!in)
    {
        cerr << "There was an error opening your file. Process terminated"; 
        exit(1); 
    }

    string outFile; 
    outFile = inFile.append(".lexer.out"); 
    ofstream out(outFile); 
    
    if(!out)
    {
        cerr << "There was an error creating your file. Process terminated"; 
        exit(1);
    }

    string token; 

    while(!in.eof())
    {
        char c; 
        in.get(c); 
        token += c; 
    }
    in.close(); 
    
    tokenizer.parse(token, out); 
    out.close(); 

    return 0; 
}
