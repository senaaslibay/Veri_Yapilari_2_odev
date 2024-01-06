/** 
* @file LinkedList.cpp
* @description AVL ağaçlarının tutulduğu LinkedList'in classının bulunduğu kaynak dosyasıdır.
* @course 2.Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 09.12.2023
* @author Sena Aslıbay/sena.aslibay1@ogr.sakarya.edu.tr
**/



#include "LinkedList.hpp"

Node *LinkedList::FindPrevByPosition(int position)
{
    if (position < 0 || position > size())
        throw "Index out of range";
    int index = 0;
    Node *itr = head;
    for (; itr != NULL; itr = itr->next, index++)
    {
        if (position == index)
            return itr;
    }
    return NULL;
}

LinkedList::LinkedList()
{
    head = new Node(new AVL(),NULL);
}
Iterator LinkedList::iterator()
{
    Iterator itr(head);
    return itr;
}
bool LinkedList::isEmpty() const
{
    return head->next == NULL;
}
int LinkedList::size() const
{
    int length = 0;
    for (Node *itr = head->next; itr != NULL; itr = itr->next)
    {
        length++;
    }
    return length;
}
AVL *LinkedList::first()
{
    if (isEmpty())
        throw "Empty list";
    return head->next->item;
}
AVL *LinkedList::last()
{
    if (isEmpty())
        throw "Empty list";
    return FindPrevByPosition(size())->item;
}
void LinkedList::add(AVL *item)
{
    insert(size(), item);
}
void LinkedList::insert(int index, AVL *item)
{
    Node *prev = FindPrevByPosition(index);
    prev->next = new Node(item, prev->next);
}
void LinkedList::remove(AVL *item)
{
    int position = indexOf(item);
    removeAt(position);
}
void LinkedList::removeAt(int index)
{
    if (isEmpty())
        throw "Empty list";
    Node *del;
    Node *prev = FindPrevByPosition(index);
    del = prev->next;
    prev->next = prev->next->next;

    delete del;
}
bool LinkedList::find(AVL *item) const
{
    for (Node *itr = head->next; itr != NULL; itr = itr->next)
    {
        if (itr->item == item)
            return true;
    }
    return false;
}
int LinkedList::indexOf(AVL *item)
{
    int index = 0;
    for (Node *itr = head->next; itr != NULL; itr = itr->next, index++)
    {
        if (itr->item == item)
            return index;
    }
    throw "Index out of range";
}
ostream &operator<<(ostream &screen, LinkedList &right)
{
    if (right.isEmpty())
        screen << "Empty list";
    else
    {
        for (Node *itr = right.head->next; itr != NULL; itr = itr->next)
        {
            screen << itr->item << " ";
        }
    }
    return screen;
}
void LinkedList::clear()
{
    while (!isEmpty())
        removeAt(0);
}
LinkedList::~LinkedList()
{
    clear();
    delete head;
}