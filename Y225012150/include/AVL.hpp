#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <cmath>
#include "Stack.hpp"

using namespace std;

struct AVLNode
{
	int data;
	AVLNode *left;
	AVLNode *right;
	int height;

	AVLNode(const int &, AVLNode *, AVLNode *);
};

class AVL
{
private:
	AVLNode *root;
	Stack *stack_temp;
	Stack *stack_real;
	int ascii;
	int toplamdugumdeger = 0;
	int avl_no;

	AVLNode *SearchAndAdd(AVLNode *, const int &);

	AVLNode *SwapWithLeftChild(AVLNode *);

	AVLNode *SwapWithRightChild(AVLNode *);

	bool DeleteNode(AVLNode *&);

	void inorder(AVLNode *);

	void preorder(AVLNode *);

	void postorder(AVLNode *);

	int Height(AVLNode *);
	void PrintLevel(AVLNode *, int);

	bool Search(AVLNode *, const int &);

public:
	AVL();
	bool isEmpty() const;
	void Add(const int &);
	void inorder();
	void preorder();
	void postorder();
	void levelorder();
	int Height();
	bool Search(const int &);
	void SetAvlNo(int);
	int getAvlNo();
	char GetAsciiChar();
	int getStackTop();
	bool isEmptyStack();
	void popStack();
	void refillStack();
	void Clear();
	~AVL();
};

#endif