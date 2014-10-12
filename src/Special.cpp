// Special.cpp -- the implementation of the special form classes

#include "Special.h"

void
Quote::print(Node * t, int n, bool p) {
  // TODO: implement this function.
}

void
Lambda::print(Node * t, int n, bool p) {
  // TODO: implement this function.
}

void
Begin::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->beginVal->print(n,p);
}

void
If::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->ifVal->print(n,p);
}

void
Let::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->letVal->print(n,p);
}

void
Cond::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->condVal->print(n,p);
}

void
Define::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->defineVal->print(n,p);
}

void
Set::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->setVal->print(n,p);
}

void
Regular::print(Node * t, int n, bool p) {
	this->regVal->print(n,p);
}
