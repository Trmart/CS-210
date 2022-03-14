#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector> 
#include <fstream> 
#include <iostream> 
#include <ctype.h> 
using namespace std; 

class Parser
{
public: 
   void parse(string &inFile); 

private: 
    enum State
    {
        UNKNOWN,
        COMMENT, 
        STRING, 
        KEYWORD, 
        IDENTIFIER, 
        OPERATOR
    }; 

    void copy(istream &in, ostream &out); 
    void parseComment(istream &in, ostream &out); 
    void outputCategory(ostream &out, const string &str, State state) const; 

    bool isCommentStart(string &str);
    bool isCommentEnd(string &str);
    bool isWhiteSpace(string &str);  
    bool isKeyword(string &str, char nextC) const; 
    bool isOperator(string &str) const; 
    bool isWhiteSpace(string &str) const; 
    bool isIdentifier(string &str, char nextC) const; 
    bool isDelimiter(char c); 



 private:   
    string m_InputFile; 
    vector <string> m_KeyWords = {"accessor" , "and" , "array", "begin", "bool","case" ,"character", "constant", "else", "elsif",
                                    "end" ,"exit", "function", "if", "in", "integer", "interface", "is", "loop", "module", "mutator",
                                    "natural", "null" ,"of" ,"or" ,"others", "out" ,"positive" ,"procedure" ,"range", "return",
                                    "struct" ,"subtype" ,"then", "type", "when", "while"}; 

    vector <string> m_Operators = {"." "<" ">" "(" ")" "+" "-" "*" "/" "|" "&" ";" ","
                                    ":" "[" "]" "=" ":=" ".." "<<" ">>" "<>" "<=" ">="
                                    "**" "!=" "=>"}; 
};

#endif