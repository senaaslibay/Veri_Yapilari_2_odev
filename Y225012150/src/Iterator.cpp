/** 
* @file Iterator.cpp
* @description AVL ağaçlarının tutulduğu LinkedList'in Iterator classının bulunduğu kaynak dosyasıdır.
* @course 2.Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 09.12.2023
* @author Sena Aslıbay/sena.aslibay1@ogr.sakarya.edu.tr
**/



#include "Iterator.hpp"

Iterator::Iterator()
{
    head = NULL;
    current = NULL;
    prev = NULL;
}
Iterator::Iterator(Node *head)
{
    this->current = head->next;
    this->head = head;
    prev = NULL;
}
bool Iterator::hasNext()
{
    return current != NULL;
}
AVL *Iterator::next()
{
    if (current == NULL)
        throw "NULL Reference";
    prev = current;
    current = current->next;
    return prev->item;
}
void Iterator::remove()
{
    if (prev == NULL)
        throw "NULL Reference";
    Node *itr = head;
    for (; itr->next != prev; itr = itr->next)
    {
    }
    Node *del = itr->next;
    itr->next = itr->next->next;
    delete del;
    prev = NULL;
}
