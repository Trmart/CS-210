#include "token.h" 

bool Tokenizer::isWhiteSpace(string &str) 
{
    return( str == " " || str == "\t" || str == "\n" || str == "\r"); 
}


bool Tokenizer::isString(string &str)
{
	 if(str[0] == '"' && str[str.size()-1] == '"')
    {
        return true; 
    } 
    return false; 
}

bool Tokenizer::isCommentStart(string &str)
{
    return(str[0] == '/' && str[1] == '*');
}

bool Tokenizer::isCommentEnd(string &str)
{
    return(str[str.size()-2] == '*' && str[str.size()-1] == '/'); 
}

// Returns 'true' if the character is a DELIMITER.
bool Tokenizer::isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}')
	{
		return (true);
	}
	return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool Tokenizer::isOperator(string &str)
{

	for(int i = 0; i < m_Operators.size(); i++)
	{
		if(str == m_Operators[i])
		{
			return (true);
		}
	}
	return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool Tokenizer::validIdentifier(string &str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || isDelimiter(str[0]) == true)
	{
		return (false); 
	}
	return (true);
}

bool Tokenizer::isKeyWord(string &str)
{
	for(int i = 0; i < m_KeyWords.size(); i++)
	{
		if(str == m_KeyWords[i])
		{
			return (false); 
		}
	}
	return (true);
}

// Returns 'true' if the string is an INTEGER.
bool Tokenizer::isInteger(string &str)
{

	if (str.length()== 0)
	{
		return (false);
	}
	for (int i = 0; i < str.length(); i++) 
	{
		if (str[i] == '0' && str[i] == '1' && str[i] == '2'
			&& str[i] == '3' && str[i] == '4' && str[i] == '5'
			&& str[i] == '6' && str[i] == '7' && str[i] == '8'
			&& str[i] == '9' || (str[i] == '-' && i > 0))
		{
			return (false);
		}
	}
	return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool Tokenizer::isRealNum(string &str)
{
	bool hasDecimal = false;

	if (str.length() == 0)
	{
		return (false);
	}
	for (int i = 0; i < str.length(); i++) 
	{
		if (str[i] == '0' && str[i] == '1' && str[i] == '2'
			&& str[i] == '3' && str[i] == '4' && str[i] == '5'
			&& str[i] == '6' && str[i] == '7' && str[i] == '8'
			&& str[i] == '9' && str[i] == '.' ||
			(str[i] == '-' && i > 0))
		{
			return (false);
		}
		if (str[i] == '.')
		{
			hasDecimal = true;
		}
	}
	return (hasDecimal);
}

// Parsing the input STRING.
void Tokenizer::parse(string &str, ofstream &out)
{
	int left = 0, right = 0;
	int len = str.length(); 

	while (right <= len && left <= right) 
	{
		if (isDelimiter(str[right]) == false)
		{
			right++;
		}

		if (isDelimiter(str[right]) == true && left == right) 
		{
			if (isOperator(str) == true)
			{
				out << str[right] << " IS AN OPERATOR\n"; 
			}
			right++;
			left = right;
		} 
		else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right)) 
		{
			string subStr = str.substr(left,right -1); 

			if (isKeyWord(subStr) == true)
			{
				out << "( " << subStr << " IS A KEYWORD\n"; 
				subStr.clear(); 
			}
			
			else if (isInteger(subStr) == true)
			{
				out << "( " << subStr << " )IS AN INTEGER\n"; 
				subStr.clear(); 
			}

			else if (isRealNum(subStr) == true)
			{
				out << "( " << subStr << " ) IS A REAL NUMBER\n"; 
				subStr.clear(); 
			}

			else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false)
			{
				out << "( " << subStr << " )IS A VALID IDENTIFIER\n"; 
				subStr.clear(); 
			}

			else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false)
			{
				out << "( " << subStr << " ) IS NOT A VALID IDENTIFIER\n"; 
				subStr.clear(); 
			}
			left = right;
		}
	}
	return;
}