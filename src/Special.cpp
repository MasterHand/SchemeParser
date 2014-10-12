// Special.cpp -- the implementation of the special form classes

#include "Special.h"

void
Quote::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->quoteVal->print(n);
}

void
Lambda::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->lambdaVal->print(n);
}

void
Begin::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->beginVal->print(n);
	cout << endl;

}

void
If::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->ifVal->print(n);
}

void
Let::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->letVal->print(n);
}

void
Cond::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->condVal->print(n);
}

void
Define::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->defineVal->print(n);
}

void
Set::print(Node * t, int n, bool p) {
  // TODO: implement this function.
	this->setVal->print(n);
}

void
Regular::print(Node * t, int n, bool p) {
	this->regVal->print(n,p);
}
