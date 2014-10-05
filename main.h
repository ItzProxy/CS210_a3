#ifndef _MAIN_H_
#define _MAIN_H_

// A fake single line text editor program.
#include <iostream>

// Header file needed by system ().
#include <cstdlib>

// Some C-specific header files needed by getch ().
// JUST USE THEM.
#include <unistd.h>
#include <termios.h>

using namespace std;

const int MAX_TEXT_LENGTH = 65;
struct node{
	char value;
	int position;
	node* next;
	node* previous;
};

class list{
public:
	list(); //default contructor
	//setters
	void setCurrentPVal(char x){ p->value = x; }
	void setP(node* n){ p = n; };
	void setLen(int len){ length = len; }
	//getters
	node* getHead(){ return head; }
	node* getP(){ return p; }
	int getLen(){ return length; }

	void insertTail(char x);
	void resetToHead();
	void insert(char x);
	void reset();
	char readP();
	void iteratePrint();
	void iterateLeft();
	void iterateRight();
	void deleteNode();
	void backdelNode();
	void findTail();
private:
	node* head;
	node* p;
	int length;
};

#endif
#include "main_cpp.cpp"