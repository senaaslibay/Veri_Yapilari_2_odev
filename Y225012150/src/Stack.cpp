/** 
* @file Stack.cpp
* @description AVL ağaçlarının yaprak değerlerini tutan yığıt classının bulunduğu kaynak dosyasıdır. 
* @course 2.Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 09.12.2023
* @author Sena Aslıbay/sena.aslibay1@ogr.sakarya.edu.tr
**/




#include "Stack.hpp"

StackNode::StackNode(int &item, StackNode *next = NULL)
{
    this->item = item;
    this->next = next;
}

Stack::Stack()
{
    topOfStack = NULL;
}
bool Stack::isEmpty() const
{
    return topOfStack == NULL;
}
void Stack::push(int &item)
{
    topOfStack = new StackNode(item, topOfStack);
}
void Stack::pop()
{
    if (isEmpty())
        throw "Stack is Empty";
    StackNode *tmp = topOfStack;
    topOfStack = topOfStack->next;
    delete tmp;
}
int &Stack::top() const
{
    if (isEmpty())
        throw "Stack is Empty";
    return topOfStack->item;
}
void Stack::makeEmpty()
{
    while (!isEmpty())
        pop();
}
Stack::~Stack()
{
    makeEmpty();
}
