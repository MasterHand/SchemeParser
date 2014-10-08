// Parser.cpp -- the implementation of class Parser

#include "Parser.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/*
 0"QUOTE",				// '
 1"LPAREN",				// (
 2"RPAREN",				// )
 3"DOT",				// .
 4"TRUET",				// #t
 5"FALSET",				// #f
 6"INT",				// integer constant
 7"STRING",				// string constant
 8"IDENT"				// identifier
 */

Node * Parser::parseExp() {
	cout << "calling parseExp()" <<endl;

	Token *token = scanner->getNextToken();//
	cout << "token type is..pExp " << token->getType() << endl;


	if (token != NULL){
			return parseExp(token);
	}else
		cout << "parseExp() token == NULL" << endl;
	return NULL;
}
Node * Parser::parseRest() {
	cout << "calling parseRest()" << endl;
	Token * token = scanner->getNextToken();

	cout << "token type is..pREST " << token->getType() << endl;

	if (token != NULL){
		return parseRest(token);
	}else
		cout << "parseRest() token == NULL" << endl;
	return NULL;
}

// TODO: Add any additional methods you might need.
Node * Parser::parseExp(Token * token) {

	 //token = scanner->getNextToken();

	//check if token is null
	cout << "calling parseExp(token*t)" << endl;
	cout << "token type is " << token->getType() << endl;



	if (token == NULL){
		cout << "null token"<< endl;
		return NULL;
	}

cout << "token not null" << endl;
	cout << "token type is " << token->getType() << endl;


	 if (token->getType() == LPAREN){
		cout << "Lparen" << endl;

		return parseRest(token); // returns to parseRest where it accepts no args and moves on to the next token
	 }
	else if (token->getType() == TRUET)
		return new BoolLit(true);
	else if (token->getType() == FALSET)
		return new BoolLit(false);
	else if (token->getType() == IDENT)
			return new Ident(token->getName());
	else if (token->getType() == INT)
		return new IntLit(token->getIntVal());
	else if (token->getType() == STRING)
		return new StrLit(token->getStrVal());


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

	//token = scanner->getNextToken();

	cout << "in rest() token type is " << token->getType() << endl;


	if (token == NULL) {
		cout <<"pRest null token" << endl;
		return NULL;
	}


	if (token->getType() == RPAREN){
		return new Nil();
	}
	else if (token->getType() == DOT)
		return new Cons(parseExp(), parseRest());

	else{
		cout << "new cons(parseExp(token), parseRest()) " << endl;
		return new Cons(parseExp(), parseRest());
	}
	//return NULL;
}

