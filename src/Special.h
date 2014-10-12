// Special.h -- the parse tree node data structure for special forms
//
// Defines the types
//
//   class Special;
//   class Quote : public Special;
//   class Lambda : public Special;
//   class Begin : public Special;
//   class If : public Special;
//   class Let : public Special;
//   class Cond : public Special;
//   class Define : public Special;
//   class Set : public Special;
//   class Regular : public Special;

#ifndef SPECIAL_H
#define SPECIAL_H

#include <iostream>

using namespace std;

#include "Tree.h"

#ifndef NULL
#define NULL 0
#endif
#define FALSE 0
#define TRUE  1

// There are several different approaches for how to implement the Special
// hierarchy.  We'll discuss some of them in class.  The easiest solution
// is to not add any fields and to use empty constructors.

class Special {
 public:
	 virtual void print(Node * t, int n, bool p){
		 cout << t;
	 }
};

class Quote : public Special {
 private:
  // TODO: Add any fields needed.
	Node * quoteVal;

 public:
  // TODO: Add an appropriate constructor.
	Quote(Node * n) {
		quoteVal = n;
	}

  virtual void print(Node * t, int n, bool p);
};


class Lambda : public Special {
 private:
  // TODO: Add any fields needed.
	Node * lambdaVal;

 public:
  // TODO: Add an appropriate constructor.
	Lambda(Node * n) {
		lambdaVal = n;
	}

  virtual void print(Node * t, int n, bool p);
};


class Begin : public Special {
 private:
  // TODO: Add any fields needed.
	Node * beginVal;

 public:
  // TODO: Add an appropriate constructor.
	Begin(Node *n) {
		beginVal = n;
	}

  virtual void print(Node * t, int n, bool p);
};


class If : public Special {
 private:
  // TODO: Add any fields needed.
	Node *ifVal;

 public:
  // TODO: Add an appropriate constructor.
	If(Node *n) {
		ifVal = n;
	}

  virtual void print(Node * t, int n, bool p);
};


class Let : public Special {
 private:
  // TODO: Add any fields needed.
	Node *letVal;

 public:
  // TODO: Add an appropriate constructor.
	Let(Node * n) {
		letVal = n;
	}

  virtual void print(Node * t, int n, bool p);
};


class Cond : public Special {
 private:
  // TODO: Add any fields needed.
	Node * condVal;

 public:
  // TODO: Add an appropriate constructor.
	Cond(Node * n) {
		condVal = n;
	}

  virtual void print(Node * t, int n, bool p);
};


class Define : public Special {
 private:
  // TODO: Add any fields needed.
	Node *defineVal;

 public:
  // TODO: Add an appropriate constructor.
	Define(Node *n) {
		defineVal = n;
	}

  virtual void print(Node * t, int n, bool p);
};


class Set : public Special {
 private:
  // TODO: Add any fields needed.
	Node *setVal;



 public:
  // TODO: Add an appropriate constructor.
	Set(Node * n){
		setVal = n;
		}

  virtual void print(Node * t, int n, bool p);
};


class Regular : public Special {
 private:
  // TODO: Add any fields needed.
	 Node * regVal;

 public:
  // TODO: Add an appropriate constructor.
	Regular(Node * n) {
		regVal = n;
	}

  virtual void print(Node * t, int n, bool p);
};

#endif
