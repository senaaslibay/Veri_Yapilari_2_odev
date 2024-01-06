/** 
* @file Node.cpp
* @description AVL ağaçlarının tutulduğu LinkedList'in Node classının bulunduğu kaynak dosyasıdır. 
* @course 2.Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 09.12.2023
* @author Sena Aslıbay/sena.aslibay1@ogr.sakarya.edu.tr
**/




#include "Node.hpp"

Node::Node(AVL *item = new AVL(), Node *nx = NULL)
{
	this->item = item;
	this->next = nx;
}

