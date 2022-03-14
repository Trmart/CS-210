#include "parser.h"

void Parser::copy(istream &in, ostream &out)
{
    char c; 

    while (!in.eof())
    {
        in.get(c); 
        out << c; 
    }
    
}
// void Parser::parseComment(istream &in, ostream &out)
// {

// }

void Parser::outputCategory(ostream &out, const string &str, State state) const
{
    out << "(" << str << ")" << state << endl; 
}

bool Parser::isCommentStart(string &str)
{
    return(str == "/*");
}

bool Parser::isCommentEnd(string &str)
{
    return(str == "*/"); 
}


bool Parser::isWhiteSpace(string &str) const
{
    return( str == " " || str == "\t" || str == "\n" || str == "\r"); 
}


bool Parser::isKeyword(string &str, char nextC) const
{
    
}


bool Parser::isOperator(string &str) const
{
    Parser parser;

    for(int i = 0; i < parser.m_Operators.size(); i++)
    {
        if(isWhiteSpace(str))
        {
            return false; 
        }
        if(str == parser.m_Operators[i])
        {
            return true;
        }
        else 
            continue; 
    }
}


// bool Parser::isIdentifier(string &str, char nextC) const
// {

// }


bool Parser::isDelimiter(char c)
{
    auto const isAllowedInName = isalnum(c) || c == '_'; 
    return !isAllowedInName; 
}

void Parser::parse(string &inFile)
{
    ifstream in(inFile); 
    string outFile; 
    outFile = inFile.append(".lexer.out"); 
    ofstream out(outFile); 
    if(!in)
    {
        cerr << "There was an error opening your file. Process terminated"; 
        exit(1); 
    }
    if(!out)
    {
        cerr << "There was an error creating your file. Process terminated"; 
        exit(1);
    }
    string token; 

    //copy(in,out); 
    Parser parser; 

    while(!in.eof())
    {
        char c; 
        in.get(c); 
        char nextC = in.peek(); 
        State state = UNKNOWN; 

        switch (state)
        {
            case UNKNOWN:
                if(parser.isOperator(token))
                {
                    state = OPERATOR; 
                }
                if(parser.isKeyword(token,nextC))
                {
                    state = KEYWORD; 
                }
                if(parser.isIdentifier(token, nextC))
                {
                    state = IDENTIFIER; 
                }
                if(parser.isCommentStart(token) && parser.isCommentEnd(token))
                {
                    state = COMMENT; 
                }
                // if()
                // {
                //    state = STRING;  
                // }
                else
                {   
                    token += c; 
                    state = UNKNOWN; 
                }
                break;

            case COMMENT:
                parser.outputCategory(out,token,state); 
                token.clear();
                state = UNKNOWN; 
                break; 

            case STRING:
                parser.outputCategory(out,token,state); 
                token.clear();
                state = UNKNOWN; 
                break; 

            case KEYWORD: 
                parser.outputCategory(out,token,state); 
                token.clear();
                state = UNKNOWN; 
                break; 

            case IDENTIFIER:
                parser.outputCategory(out,token,state); 
                token.clear();
                state = UNKNOWN; 
                break; 

            case OPERATOR: 
                parser.outputCategory(out,token,state); 
                token.clear();
                state = UNKNOWN; 
                break; 

        default:
            break;
        }

    }
}