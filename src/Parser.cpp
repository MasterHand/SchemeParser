/*
 * scratch.h
 *
 *  Created on: Oct 9, 2014
 *      Author: andrewbergeron
 */
#include "Parser.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

Node * Parser::parseExp(){
	cout << "calling parseExp()" << endl;
	return parseExp(scanner->getNextToken());
}
Node * Parser::parseRest(){
	cout<< "calling parseRest()"<< endl;
	return parseRest(scanner->getNextToken());
}


Node * Parser::parseExp(Token * token){

	token = scanner->getNextToken();

	Node *expr = NULL;

	if (token != NULL){
		cout<<"token not null ===exp " << token << endl;

		if (token->getType() == LPAREN){
			cout <<"Lparen" << endl;
			return parseRest(token);
		}
		else if (token->getType() ==TRUET){
			expr = new BoolLit(true);
		}
		else if (token->getType() == FALSET){
			expr = new BoolLit(false);
		}
		else if (token->getType() == IDENT){
			expr = new Ident(token->getName());
		}
		else if (token->getType() == INT){
			expr = new IntLit(token->getIntVal());
		}
		else if (token->getType() == STRING){
			expr = new StrLit(token->getStrVal());
		}
		else if (token->getType() == QUOTE){
			expr = new Cons(new Ident("quote"), new Cons(parseExp(), new Nil()));
		}else
			return expr;



	}
	cout <<"return expr exp " << expr << endl;
		return expr;


}
Node * Parser::parseRest(Token * token){

	token = scanner->getNextToken();

	Node * expr = NULL;

	if (token != NULL){
		cout<<"token not null ===rest " << token << endl;

		if (token->getType() == RPAREN){
			expr = new Nil();
		}
		else if (token->getType() == DOT){
			expr = new Cons(parseExp(), parseRest());
		}else
		cout << "new Cons(parseExp, parseRest)" << endl;
				expr = new Cons(parseExp(token), parseRest());

	}
	cout <<"return expr rest" << expr << endl;
		return expr;

}
