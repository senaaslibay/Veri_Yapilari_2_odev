#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "AVL.hpp"
using namespace std;

class Node
{
public:
	AVL *item;
	Node *next;
	Node(AVL *, Node *);
};
#endif