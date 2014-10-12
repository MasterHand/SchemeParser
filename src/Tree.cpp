// Tree.cpp -- the implementation of the tree classes

#include "Tree.h"
#include "Special.h"
#include <typeinfo>
#include <string>

void BoolLit::print(int n) {
	printSpace(n);
	cout << (boolVal ? "#t" : "#f");
	cout << " ";
}

void IntLit::print(int n) {
	printSpace(n);
	cout << intVal;
	cout << " ";
}

void StrLit::print(int n) {
	printSpace(n);
	cout << '"' << strVal << '"';
	cout << " ";
}

void Ident::print(int n) {
	printSpace(n);
	cout << name;

	cout << " ";

}

void Nil::print(int n, bool p) {

	cout << (p ? ")" : "()");
	cout << " ";
}

void Cons::print(int n) {
	cout << "(";
	this->print(n, false);

}

void Cons::print(int n, bool p) {


	form->print(this, n, p);
	cdr->print(n, true);
}

void Cons::parseList() {
	// TODO: implement this function and any helper functions you might need.
	//bool isSymbol = car->isSymbol();

	string name = car->getName();

	if (name == "'") {
		form = new Quote(car);
	} else if (name == "lambda") {
		form = new Lambda(car);
	} else if (name == "begin") {
		form = new Begin(car);
	} else if (name == "if") {
		form = new If(car);
	} else if (name == "let") {
		form = new Cond(car);
	} else if (name == "define") {
		form = new Define(car);
	} else if (name == "set!") {
		form = new Set(car);
	} else {
		form = new Regular(car);
	}

}
