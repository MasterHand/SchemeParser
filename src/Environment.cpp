// Environment.cpp -- a data structure for Scheme environments

#include "Environment.h"
#include <cstring>

using namespace std;

void
Environment::print(int n) {
  // there got to be a more efficient way to print n spaces
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << "#{Environment" << endl;
  scope->print(n+3);
  if (env != NULL)
    env->print(n+3);
  for (int i = 0; i < n; i++)
    cout << ' ';
  cout << '}' << endl;
}


// This is not in an object-oriented style, it's more or less a
// translation of the Scheme assq function.
static Node *
find (Node * id, Node * alist) {
  if (! alist->isPair())
    return NULL;	// in Scheme we'd return #f
  else {
    Node * bind = alist->getCar();
    if (strcmp(id->getName(), bind->getCar()->getName()) == 0)
      // return a list containing the value as only element
      return bind->getCdr();
    else
      return find(id, alist->getCdr());
  }
}

Node *
Environment::lookup (Node * id) {
  Node * val = find(id, scope);
  if (val == NULL && env == NULL) {
    cerr << "undefined variable" << endl;
    return NULL;
  }
  else if (val == NULL)
    // look up the identifier in the enclosing scope
    return env->lookup(id);
  else
    // get the value out of the list we got from find()
    return val->getCar();
}

void
Environment::define (Node * id, Node * val) {
  // TODO: implement this function
	Node *value = find(id, scope);

	if(value == NULL){
		scope = new Cons(new Cons(id, new Cons(val, new Nil())), scope);
	}
	else{
		value->setCar(val);
	}




}

void
Environment::assign (Node * id, Node * val) {
  // TODO: implement this function

  // You can use find() to get a list containing the value and
  // then update the value using setCar()
	Node * value = find(id, scope);

	if (value == NULL && env == NULL){
		cerr <<"undefined variable bro.";
	}
	else if(value == NULL){
		assign(id, env);
	}
	else{
		setCar(new Cons(id, val));
	}


}
Node*
Environment::eval(Environment * env){
	return new Nil();
}

Node*
Environment::eval(Node *t, Environment * env){
	return new Nil();
}
/*
Node*
Environment::evalBody(Node *t, Environment * env){
	return new Nil();
}
*/
