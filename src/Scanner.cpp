// Scanner.cpp -- the implementation of class Scanner

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


#include "Scanner.h"

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

  else if (ch == ' ' || ch == '\n')
	  return getNextToken();

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
	  in->get(ch);     //re- declare the stream object as a look-ahead to next character



	  cout << "testing666" << endl;

	 int count = 0;

	  while (ch != '"'){
		  buf[count] = ch;
		  ++count;
		  in->get(ch);

	  }



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

		cout << "testing123" << endl;



    return new StrToken(buf);

  }

  // Integer constants
  else if (ch >= '0' && ch <= '9') {
    // TODO: scan the number and convert it to an integer


	 int i = 10*i + ch - '0';



    // put the character after the integer back into the input
     in->putback(ch);


    return new IntToken(i);
  }

  // Identifiers
  else if ((ch >= 'A' && ch <= 'Z')||  /* ascii 65-90 */
		  (ch >= '#' && ch <= '/') ||  /* ascii 33-47 */
		  (ch >= ':' && ch <= '@') ||   /* ascii 58-64 */
		  (ch >= '^' && ch <= '_') || /* ascii 94-95 */
		  (ch = '~') /* ascii 126 */
		  )
	   /* or ch is some other valid first character for an identifier */ {

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
