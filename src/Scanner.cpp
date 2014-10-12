// Scanner.cpp -- the implementation of class Scanner

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <math.h>

#include "Scanner.h"



void Scanner:: clearBuf(){ // must clear the buffer char array after each use. This should fix duplicates
	size = 0;
	delete[] buf; 	//delete any existing buffer array object
	buf = new char[BUFSIZE]; 	//create a new buffer
	buf[size] = '\0'; 	//append the char array with nul terminator

}

Token *
Scanner::getNextToken() {
	char ch;

	// It would be more efficient if we'd maintain our own input buffer
	// and read characters out of that buffer, but reading individual
	// characters from the input stream is easier.
	in->get(ch);

	// TODO: skip white space and comments

	if (in->eof())
		return NULL;
	// skips whitesapce, newline, tab, vertical tab, horizontal tab, carriage return, form feed
	if (ch == ' ' || ch == '\n' || ch == '\t' ||
		ch == '\v' || ch == '\r' || ch == '\f')
		return getNextToken();

	if (ch == ';') {
		while (!(ch == '\n'))
			in->get(ch);
		return getNextToken();
	}
	// Special characters
	else if (ch == '\'')
		return new Token(QUOTE);
	else if (ch == '(')
		return new Token(LPAREN);
	else if (ch == ')')
		return new Token(RPAREN);
	else if (ch == '.')
		// We ignore the special identifier `...'.
		return new Token(DOT);

	// Boolean constants
	else if (ch == '#') {
		in->get(ch);
		if (ch == 't')
			return new Token(TRUET);
		else if (ch == 'f')
			return new Token(FALSET);
		else {
			cerr << "Illegal character '" << ch << "' following #" << endl;
			return getNextToken();
		}
	}

	// String constants
	else if (ch == '"') {
		// TODO: scan a string into the buffer variable buf
		in->get(ch); //re- declare the stream object as a look-ahead to next character

		clearBuf();


		while (ch != '"') {
			buf[size] = ch;
			++size;
			in->get(ch);

		}
		buf[size] = '\0';

		return new StrToken(buf);
	}

	// Integer constants
	else if (ch >= '0' && ch <= '9') {
		// TODO: scan the number and convert it to an integer
		//in->get(ch);

		std::stack<int> theStack;  //LIFO STACK

		while (ch >= '0' && ch <= '9'){
			theStack.push((ch - '0'));
			in->get(ch);
		}
		int intVals = 0;
		int i = 0;



		while (!theStack.empty()){
			intVals = intVals + theStack.top() * pow(10.0, i++);
			theStack.pop();

		}
		//cout << ' ' << theStack.top(); this will print the stack from top down
				//we need to take each number in the stack  5 2 2 and make it 225, use some math
				/*example 225 ...
						0  + 5* (10^0) = 5
						5  + 2* (10^1) = 25
						25 + 2* (10^2) = 225 !!!*/

		// put the character after the integer back into the input
		in->putback(ch);

		return new IntToken(intVals);

	}

	// Identifiers
	else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
	//or ch is some other valid first character for an identifier

		// TODO: scan an identifier into the buffer
		//in->get(ch);

		clearBuf();

		while (!(ch == ' ' || ch == ')' || ch == '\n' )){  //an identifier might end with a space or closing paren
			//put on stack or buf variable
			buf[size] = ch;
			++size;
			in->get(ch); //return ch to int input stream and analyze next char
		}

		// put the character after the identifier back into the input
		//in->putback(ch);

		return new IdentToken(buf);
	}

	else if (ch == '!' || ch == '$' || ch == '%' || ch == '&' || ch == '*' || ch == '+'
			|| ch == '-' || ch == '.' || ch == '/' || ch == ':' || ch == '<' || ch == '>'
			|| ch == '=' || ch == '?' || ch == '@' || ch == '^' || ch == '_' || ch == '~'){

		//remember !=, ==, >=, <=, <<, >>, ++, --
		clearBuf();
		while (!(ch == ' ' || ch == ')' || ch == '\n')){
			buf[size] = ch;
			++size;
			in->get(ch);
		}


		return new IdentToken(buf);
	}


	// Illegal character
	else {
		cerr << "Illegal input character '" << ch << '\'' << endl;
		return getNextToken();
	}
}
