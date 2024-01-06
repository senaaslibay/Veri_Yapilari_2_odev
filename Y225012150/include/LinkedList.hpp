#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>

// #include "Node.hpp"
#include "Iterator.hpp"

using namespace std;


class LinkedList
{
private:
	Node *head;

	Node *FindPrevByPosition(int);

public:
	LinkedList();
	Iterator iterator();
	bool isEmpty() const;
	int size() const;
	AVL *first();
	AVL *last();
	void add(AVL *);
	void insert(int, AVL *);
	void remove(AVL *);
	void removeAt(int);
	bool find(AVL *) const;
	int indexOf(AVL *);
	friend ostream &operator<<(ostream &, LinkedList &);
	void clear();
	~LinkedList();
};
#endif