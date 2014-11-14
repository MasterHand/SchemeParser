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
#include "Tree.h"

#ifndef NULL
#define NULL 0
#endif
#define FALSE 0
#define TRUE  1

class Special {
 public:
  virtual void print(Node * t, int n, bool p) = 0;

  virtual Node *eval(Environment * env);
  virtual Node *eval(Node * t, Environment * env);
  virtual Node *evalBody(Node *t, Environment *env);

};

// The constructors of the following classes take a pointer to the
// cons node as argument that create the special node object.  This
// allows adding any necessary parsing code later.




class Quote : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  Quote (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);
};


class Lambda : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  Lambda (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);

};


class Begin : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  Begin (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);

};


class If : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  If (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);

};


class Let : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  Let (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);
  virtual Node *evalBody(Node *t, Environment *env);


};


class Cond : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  Cond (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);

};


class Define : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  Define (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);

};


class Set : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  Set (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);

};


class Regular : public Special {
 private:
  // TODO: Add any fields needed.

 public:
  Regular (Node * t) { }

  virtual void print(Node * t, int n, bool p);
  virtual Node *eval(Node *t, Environment *env);

};

#endif
