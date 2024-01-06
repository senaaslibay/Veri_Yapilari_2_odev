#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

class StackNode
{
public:
	int item;
	StackNode *next;

	StackNode(int &, StackNode *);
};

class Stack
{
private:
	StackNode *topOfStack;

public:
	Stack();
	bool isEmpty() const;
	void push(int &);
	void pop();
	int &top() const;
	void makeEmpty();
	~Stack();
};

#endif