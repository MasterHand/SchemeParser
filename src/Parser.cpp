// Parser.cpp -- the implementation of class Parser

#include "Parser.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
	cout << "calling parseExp " <<endl;
			return parseExp(scanner->getNextToken());

}
Node * Parser::parseRest() {

	cout << "calling parseRest" << endl;
		return parseRest(scanner->getNextToken());

}

// TODO: Add any additional methods you might need.
Node * Parser::parseExp(Token * token) {

	token = scanner->getNextToken();

	//check if token is null
	cout << "calling parseExp(token*t)" << endl;


	if (token == NULL){
		return NULL;
	}


	if (token->getType() == LPAREN){
		cout << "token type is paren" << endl;

		return parseRest(); // returns to parseRest where it accepts no args and moves on to the next token
	}
	else if (token->getType() == TRUET)
		return new BoolLit(true);
	else if (token->getType() == FALSET)
		return new BoolLit(false);
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //QUOTE, from notes, new identifier as car node,
																		  //cdr node is now a cons branching down to parseExp() and Nil()
	else if (token->getType() == INT)
		return new IntLit(token->getIntVal());
	else if (token->getType() == STRING)
		return new StrLit(token->getStrVal());
	else if (token->getType() == IDENT)
		return new Ident(token->getName());

	else if (token->getType() == QUOTE)
			return new Cons(new Ident("'"), new Cons(parseExp(), new Nil()));


	else{
		cout << "token fell thru parseExp missed something" << endl;
		return parseExp();
	}


	//return NULL;
}

Node * Parser::parseRest(Token * token) {

	cout << "calling parseRest(token*t)" << endl;

	if (token == NULL) {
		return NULL;
	}


	if (token->getType() == RPAREN){
		return new Nil();
	}
	else if (token->getType() == DOT)
		return new Cons(parseExp(), parseRest());

	else{
		cout << "fell thru parseRest " << endl;
		return new Cons(parseExp(token), parseRest());
	}
	//return NULL;
}

