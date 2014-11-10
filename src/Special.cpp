// Special.cpp -- the implementation of the special form classes

#include "Special.h"
#include "Printer.h"
#include "Tree.h"
using namespace std;

// The print() methods for the Special node hierarchy were moved
// to file Special-print.cpp.  You can add your own code to the
// Special node hierarchy in this file and simply link in the
// compiled print() methods in Special-print.o by adding the file
// Special-print.o to the variable OBJ in the Makefile.

Node* Quote::eval(Node *t, Environment *env){

	return t->getCdr()->getCar();
}

Node* Lambda::eval(Node *t, Environment *env){
	return new Closure(t->getCdr(), env);

}

Node* Begin::eval(Node *t, Environment *env){
	return NULL;
}

Node* If::eval(Node *t, Environment *env){

	Node *cond;
	Node *expr;

	cond = t->getCdr()->getCar();
	if(cond->eval(env)->isBool()){
		expr = t->getCdr()->getCdr()->getCar();
		return expr->eval(env);
	}
	else if (!(t->getCdr()->getCdr()->getCdr())->isNull()){
		expr = t->getCdr()->getCdr()->getCar();
		return expr->eval(env);
	}
	else{
		cerr <<"undefined variable bro.";
		return new Nil();
	}

}

Node* Let::eval(Node *t, Environment *env){
	Node *args;
	Node * expr;

	Environment *local = new Environment(env);
	args = t->getCdr()->getCar();
	expr = t->getCdr()->getCdr()->getCar();
	args = evalBody(args, local);
	return expr->eval(local);

}

Node *Let::evalBody(Node *t, Environment *env){

	if (t == NULL || t->isNull()) {
				Node *alist = new Cons(new Nil(), new Nil());
				return alist;
			} else {
				Node * arg;
				Node * exp;
				Node * rest;

				arg = t->getCar()->getCar();
				exp = t->getCar()->getCdr()->getCar();
				rest = t->getCdr();

				if (arg->isSymbol()) {
					env->define(arg, exp->eval(env));
					return evalBody(rest, env);
				} else if (arg->isPair()) {
					return arg->eval(env);
				} else if (arg == NULL || arg->isNull()) {
					return new Nil();
				}
			}
			return NULL;
		}

Node * Cond::eval(Node *t, Environment *env){
		Node *exp;

			exp = t->getCdr();

			while ((!(exp->getCar())->getCar()->eval(env)->isBool())
					&& (!exp->isNull())) {
				exp = exp->getCdr();
			}

			if (exp->isNull()) {
				return new Nil();
			} else {
				return (exp->getCar()->getCdr()->getCar()->eval(env));
			}
		}

Node * Define::eval(Node *t, Environment *env){
			Node *id;
			Node *val;

			id = t->getCdr()->getCar();
			val = t->getCdr()->getCdr()->getCar();

			if (id->isSymbol()) {
				env->define(id, val);
			} else {
				Closure *func = new Closure(new Cons(t->getCdr()->getCar()->getCdr(),
						t->getCdr()->getCdr()), env);
				env->define(id->getCar(), func);
			}

			return new StrLit("; no values returned");
		}

Node * Set::eval(Node *t, Environment *env){
	Node *id;
	Node *exp;

	id= t->getCdr()->getCar();
	exp= t->getCdr()->getCdr()->getCar();

	env->define(id, exp->eval(env));
	return new StrLit("");

}

void
Quote::print(Node * t, int n, bool p) {
  Printer::printQuote(t, n, p);
}

void
Lambda::print(Node * t, int n, bool p) {
  Printer::printLambda(t, n, p);
}

void
Begin::print(Node * t, int n, bool p) {
  Printer::printBegin(t, n, p);
}

void
If::print(Node * t, int n, bool p) {
  Printer::printIf(t, n, p);
}

void
Let::print(Node * t, int n, bool p) {
  Printer::printLet(t, n, p);
}

void
Cond::print(Node * t, int n, bool p) {
  Printer::printCond(t, n, p);
}

void
Define::print(Node * t, int n, bool p) {
  Printer::printDefine(t, n, p);
}

void
Set::print(Node * t, int n, bool p) {
  Printer::printSet(t, n, p);
}

void
Regular::print(Node * t, int n, bool p) {
  Printer::printRegular(t, n, p);
}
