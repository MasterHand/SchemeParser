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
	return parseExp(scanner->getNextToken());
}

Node * Parser::parseExp(Token * token){


	Node *expr = NULL;

	if (token != NULL){

		if (token->getType() == LPAREN){
			return parseRest();
		}
		else if (token->getType() ==TRUET){
			return getTnode();
		}
		else if (token->getType() == FALSET){
			return getFnode();
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
			expr = new Cons(new Ident("'"), new Cons(parseExp(), getNilnode()));
		}else
			return expr;



	}
		return expr;


}
Node * Parser::parseRest(){

	Token * token = scanner->getNextToken();

	Node * expr = NULL;

	if (token != NULL){

		if (token->getType() == RPAREN){
			return getNilnode();
		}
		else if (token->getType() == DOT){
			expr = new Cons(parseExp(), parseRest());
		}
		else{
			expr = new Cons(parseExp(token), parseRest());
		}

	}
		return expr;

}

Node * Parser::getNilnode(){

	if(Nilnode == NULL)
		Nilnode = new Nil();
	return Nilnode;

}

Node * Parser::getTnode(){
	if (Tnode == NULL)
		Tnode = new BoolLit(true);
	return Tnode;


}


Node * Parser::getFnode(){
	if (Fnode == NULL)
		Fnode = new BoolLit(false);
	return Fnode;
}
