// Scanner.cpp -- the implementation of class Scanner

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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
		ch == '\v' || ch == '\r'|| ch == '\f')
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

		//int count = 0;

		while (ch != '"') {
			buf[size] = ch;
			++size;
			in->get(ch);

		}
		buf[size] = '\0';

		/* we need to loop through each character and store in buf array

		 cout << ch << endl;
		 in->get(ch);
		 cout << ch << endl;
		 in->get(ch);
		 cout << ch << endl;
		 in->get(ch);
		 cout << ch << endl;
		 in->get(ch);
		 cout << ch << endl;
		 in->get(ch);
		 cout << ch << endl;

		 */

		return new StrToken(buf);
//		return getNextToken();

	}

	// Integer constants
	else if (ch >= '0' && ch <= '9') {
		// TODO: scan the number and convert it to an integer
		in->get(ch);

		//cout << ch << endl;

		int i = ch - '0';

		// x = atoi(buf);

		// put the character after the integer back into the input
		in->putback(ch);

		return new IntToken(i);
		//  return getNextToken();

	}

	// Identifiers
	else if ((ch >= 'A' && ch <= 'Z') || /* ascii 65-90 */
	(ch >= '#' && ch <= '/') || /* ascii 33-47 */
	(ch >= ':' && ch <= '@') || /* ascii 58-64 */
	(ch >= '^' && ch <= '_') || /* ascii 94-95 */
	(ch = '~') /* ascii 126 */
	)
	/* or ch is some other valid first character for an identifier */{

		// TODO: scan an identifier into the buffer
		in->get(ch);

		// put the character after the identifier back into the input
		in->putback(ch);

		return new IdentToken(buf);
	}

	// Illegal character
	else {
		cerr << "Illegal input character '" << ch << '\'' << endl;
		return getNextToken();
	}
}
