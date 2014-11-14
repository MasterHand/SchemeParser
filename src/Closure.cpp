// Closure.cpp -- the data structure for function closures

#include <iostream>
#include <cstdlib>
#include "Closure.h"
#include "Parser.h"

using namespace std;


static  Environment * interaction_environment = new Environment();


void
BuiltIn::print(int n) {
  // there got to be a more efficient way to print n spaces
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << "#{Built-in Procedure" << endl;
  symbol->print(n+3);
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << '}' << endl;
}


Node *
BuiltIn::apply(Node * args) {

	/*Check nodes for Null values and if null, creat new nils()*/
  if(args == NULL){
	return NULL;
  }

  string symName = symbol->getName();
  Node* arg1 = args->getCar();

  if (arg1 == NULL || arg1->isNull()){
	  arg1 = new Nil();
  }

  Node* arg2 = args->getCdr();

  if (arg2 == NULL || arg2->isNull()){
	  arg2 = new Nil();
  }
  else{
	  arg2 = arg2->getCar();
  }

  /* Builtin Binary Functionality */
  /* b+
   * b-
   * b/
   * b*
   * b=
   * b<
   */

  if (symName == "b+"){
	  if (arg1->isNumber() && arg2->isNumber()){
		  int a = arg1->getVal();
		  int b = arg2->getVal();
		  return new IntLit(a + b);
	  }

  else{
	  cerr << "Error: incorrect arguments for b+";
			  return new StrLit("");
  	  }
 }
  else if (symName == "b-"){
	  if (arg1->isNumber() && arg2->isNumber()){
		int a = arg1->getVal();
		int b = arg2->getVal();
		return new IntLit(a - b);
	  }
	  else{
		  cerr << "Error: incorrect arguments for b-";
		  return new StrLit("");
	  }
  }

  else if(symName == "b/"){
	  if (arg1->isNumber() && arg2->isNumber()){
		  int a = arg1->getVal();
		  int b = arg2->getVal();
		 return new IntLit(a / b);

	  }
	  else{
		  cerr << "Error:incorrect argument for b/";
		  return new StrLit("");
	  }
  }
  else if(symName == "b*"){
  	  if (arg1->isNumber() && arg2->isNumber()){
  		int a = arg1->getVal();
  		int b = arg2->getVal();
  		return new IntLit(a * b);

  	  }
  	  else{
  		  cerr << "Error:incorrect argument for b/";
		  return new StrLit("");


  	  }
    }
  else if(symName == "b="){
   	  if (arg1->isNumber() && arg2->isNumber()){
   		int a = arg1->getVal();
   		int b = arg2->getVal();


   		return new BoolLit(a == b);


   	  }
   	  else{
   		  cerr << "Error:incorrect argument for b/";
		  return new StrLit("");

   	  }
     }
  else if(symName == "b<"){
   	  if (arg1->isNumber() && arg2->isNumber()){
   		int a = arg1->getVal();
   		int b = arg2->getVal();
   		return new BoolLit(a < b);

   	  }
   	  else{
   		  cerr << "Error:incorrect argument for b/";
		  return new StrLit("");

   	  }
     }



  else if (symName =="car") {
  			if (arg1->isNull()) {
  				return arg1;
  			}
  			return arg1->getCar();
  		} else if (symName == "cdr") {
  			if (arg1->isNull()) {
  				return arg1;
  			}
  			return arg1->getCdr();
  		} else if (symName =="cons") {
  			return new Cons(arg1, arg2);
  		} else if (symName == "set-car!") {
  			arg1->setCar(arg2);
  			return arg1;
  		} else if (symName =="set-cdr!") {
  			arg1->setCdr(arg2);
  			return arg1;
  		} else if (symName =="symbol?") {
  			return new BoolLit(arg1->isSymbol());
  		} else if (symName =="number?") {
  			return new BoolLit(arg1->isNumber());
  		} else if (symName =="null?") {
  			return new BoolLit(arg1->isNull());
  		} else if (symName =="pair?") {
  			return new BoolLit(arg1->isPair());
  		}


  		else if (symName =="eq?") {
  			if (arg1->isBool() && arg2->isBool()) {
  				return new BoolLit(arg1->getBool() == arg2->getBool());
  			}
  			else if (arg1->isNumber() && arg2->isNumber()) {
  				return new BoolLit(arg1->getVal() == arg2->getVal());
  			}
  			else if (arg1->isString() && arg2->isString()) {
  				return new BoolLit(arg1->getStrVal() == arg2->getStrVal());
  			}
  			else if (arg1->isSymbol() && arg2->isSymbol()) {
  				return new BoolLit(arg1->getName() == arg2->getName());
  			}
  			else if (arg1->isNull() && arg2->isNull()) {
  				return new BoolLit(true);
  			}
  			else if (arg1->isPair() && arg2->isPair()) {
  				Node * frontArgs = new Cons(arg1->getCar(), new Cons(
  						arg2->getCar(), new Nil()));
  				Node * backArgs = new Cons(arg1->getCdr(), new Cons(arg2->getCdr(),
  						new Nil()));
  				return new BoolLit(apply(frontArgs)->getBool()
  						&& apply(backArgs)->getBool());
  			}
  			return new BoolLit(false);
  		}

  		else if (symName =="procedure?") {
  			return new BoolLit(arg1->isProcedure());
  		} else if (symName =="display") {
  			return arg1;
  		}

  		else if (symName =="newline") {
  			return new StrLit("\n");
  		} else if (symName =="exit" || symName =="quit") {
  			exit(0);


  /* READ, WRITE, APPLY, EVAL */
  		} else if (symName =="write") {
  			arg1->print(0);
  			return new StrLit("");
  		} else if (symName =="eval") {
  			return arg1;
  		}

  		else if (symName =="apply") {
  			return arg1->apply(arg2);
  		} else if (symName =="read") {
  			Parser* parser;
  			parser = new Parser(new Scanner(&cin));
  			Node* n = parser->parseExp();
  			return n;
  		} else if (symName =="interaction-environment") {
  			interaction_environment->print(0);
  		} else {
  			// use "write" as the default
  			arg1->print(0);
  			return new Nil();
  		}
  		return new StrLit(">");
  	}






void
Closure::print(int n) {
  // there got to be a more efficient way to print n spaces
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << "#{Procedure" << endl;
  fun->print(n+3);
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << '}' << endl;
}


Node *
Closure::apply(Node * args) {
 // return NULL;

	Environment *e = this->getEnv();
	Node *function = getFun();

	Node *symbol = function->getCar();
	function = function->getCdr()->getCar();

	while (args != NULL && !args->getCar()->isNull()){
		e->define(symbol->getCar(), args->getCar());
		symbol = symbol->getCdr();
		args = args->getCdr();
	}
	return function->eval(e);
}



