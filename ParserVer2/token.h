#ifndef TOKEN_H
#define TOKEN_H 
#include <string> 
#include <vector>
#include <fstream> 
#include <iostream> 
using namespace std; 

class Tokenizer
{
    public:
        void parse(string &str, ofstream &out);
    
    private:
        bool isDelimiter(char ch);
        bool isOperator(string &str);
        bool isCommentStart(string &str); 
        bool isCommentEnd(string &str);
        bool isString(string &str); 
        bool validIdentifier(string &str);
        bool isKeyWord(string &str);
        bool isInteger(string &str);
        bool isRealNum(string &str);
        bool isWhiteSpace(string &str); 
    
    private:
        vector <string> m_KeyWords = {"accessor" , "and" , "array", "begin", "bool","case" ,"character", "constant", "else", "elsif",
                                    "end" ,"exit", "function", "if", "in", "integer", "interface", "is", "loop", "module", "mutator",
                                    "natural", "null" ,"of" ,"or" ,"others", "out" ,"positive" ,"procedure" ,"range", "return",
                                    "struct" ,"subtype" ,"then", "type", "when", "while"}; 

        vector <string> m_Operators = {"." "<" ">" "(" ")" "+" "-" "*" "/" "|" "&" ";" ","
                                    ":" "[" "]" "=" ":=" ".." "<<" ">>" "<>" "<=" ">="
                                    "**" "!=" "=>"}; 
}; 

#endif