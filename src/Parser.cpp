// Parser.cpp -- the implementation of class Parser

#include "Parser.h"
/*
  "QUOTE",				// '
  "LPAREN",				// (
  "RPAREN",				// )
  "DOT",				// .
  "TRUET",				// #t
  "FALSET",				// #f
  "INT",				// integer constant
  "STRING",				// string constant
  "IDENT"				// identifier
*/

Node * Parser::parseExp() {
  // TODO: write code for parsing an exp

	cout << "calling parseExp" << endl;

	return parseExp(scanner->getNextToken());
	//return NULL;

}

Node * Parser::parseRest() {
  // TODO: write code for parsing rest

	cout << "calling parseRest" << endl;

 return parseRest(scanner->getNextToken());
  //return NULL;
}

// TODO: Add any additional methods you might need.
Node * Parser::parseExp(Token * token){

	cout << "calling parseExp(Token * token) " << "enumerated token type = " <<token->getType() << " token = " << token<<  endl;

	if (token->getType() == LPAREN)

		return parseRest(); // returns to parseRest where it accepts no args and moves on to the next token

		else if (token->getType() == TRUET)
			return new BoolLit(true);
		else if (token->getType() == FALSET)
			return new BoolLit(false);
		else if (token->getType() == QUOTE)
			return new Cons(new Ident("'"), new Cons(parseExp(), new Nil())); //from notes, new identifier as car node,
																				  //cdr node is now a cons branching down to parseExp() and Nil()
		else if (token->getType() == INT)
			return new IntLit(token->getIntVal());
		else if (token->getType() == STRING)
			return new StrLit(token->getStrVal());
		else if (token->getType() == IDENT)
			return new Ident(token->getName());

		else{
			cout << "missed something" << endl;
			return NULL;

		}

	//return NULL;
}


Node * Parser::parseRest(Token * token){


	cout << "calling parseRest(Token * token) " << token->getType() << " token =" << token << endl;


	 if (token->getType() == RPAREN)
		return new Nil();
	else if (token->getType() == DOT)
		return new Cons(parseExp(), parseRest());

	else{
		return new Cons(parseExp(token), parseRest());
	}

	//return NULL;
}



