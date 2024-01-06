#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "Node.hpp"

#include <iostream>
using namespace std;


class Iterator{
	private:
		Node *head;	
		Node *current;
		Node *prev;
	
	public:
		Iterator();
		Iterator(Node *head);
		bool hasNext();
		AVL* next();
		void remove();
};

#endif