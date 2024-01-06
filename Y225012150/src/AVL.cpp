/** 
* @file AVL.cpp
* @description AVL classının bulunduğu kaynak dosyasıdır. AVL classının içerdiği değerlere ek olarak içerisinde iki adet yığıt da saklamaktadır.
* @course 2.Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 09.12.2023
* @author Sena Aslıbay/sena.aslibay1@ogr.sakarya.edu.tr
**/




#include "AVL.hpp"

AVLNode::AVLNode(const int &vr, AVLNode *sl = NULL, AVLNode *sg = NULL)
{
    data = vr;
    left = sl;
    right = sg;
    height = 0;
}

AVLNode *AVL::SearchAndAdd(AVLNode *subNode, const int &item)
{
    if (Search(item))
    {
        return subNode;
    }
    else
    {
        if (subNode == NULL)
            subNode = new AVLNode(item);
        else if (item < subNode->data)
        {
            subNode->left = SearchAndAdd(subNode->left, item);

            if (Height(subNode->left) == Height(subNode->right) + 2)
            {
                if (item < subNode->left->data)
                    subNode = SwapWithLeftChild(subNode);
                else
                {
                    subNode->left = SwapWithRightChild(subNode->left);
                    subNode = SwapWithLeftChild(subNode);
                }
            }
        }
        else if (item > subNode->data)
        {
            subNode->right = SearchAndAdd(subNode->right, item);

            if (Height(subNode->right) == Height(subNode->left) + 2)
            {
                if (item > subNode->right->data)
                    subNode = SwapWithRightChild(subNode);
                else
                {
                    subNode->right = SwapWithLeftChild(subNode->right);
                    subNode = SwapWithRightChild(subNode);
                }
            }
        }
        else
            ;

        subNode->height = Height(subNode);
        return subNode;
    }
}
AVLNode *AVL::SwapWithLeftChild(AVLNode *subNode)
{
    AVLNode *tmp = subNode->left;
    subNode->left = tmp->right;
    tmp->right = subNode;

    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->left), subNode->height);

    return tmp;
}
AVLNode *AVL::SwapWithRightChild(AVLNode *subNode)
{
    AVLNode *tmp = subNode->right;
    subNode->right = tmp->left;
    tmp->left = subNode;

    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->right), subNode->height);

    return tmp;
}
bool AVL::DeleteNode(AVLNode *&subNode)
{
    AVLNode *delNode = subNode;

    if (subNode->right == NULL)
        subNode = subNode->left;
    else if (subNode->left == NULL)
        subNode = subNode->right;
    else
    {
        delNode = subNode->left;
        AVLNode *parentNode = subNode;
        while (delNode->right != NULL)
        {
            parentNode = delNode;
            delNode = delNode->right;
        }
        subNode->data = delNode->data;
        if (parentNode == subNode)
            subNode->left = delNode->left;
        else
            parentNode->right = delNode->left;
    }
    delete delNode;
    return true;
}
void AVL::inorder(AVLNode *subNode)
{
    if (subNode != NULL)
    {
        inorder(subNode->left);
        // cout << subNode->data << " ";
        inorder(subNode->right);
    }
}
void AVL::preorder(AVLNode *subNode)
{
    if (subNode != NULL)
    {
        // cout << subNode->data << " ";
        preorder(subNode->left);
        preorder(subNode->right);
    }
}
void AVL::postorder(AVLNode *subNode)
{
    if (subNode != NULL)
    {
        postorder(subNode->left);
        postorder(subNode->right);
        if (Height(subNode) == 0)
        {
            // cout << "yaprak: " << subNode->data << endl;
            stack_real->push(subNode->data);
            // stack_temp->push(subNode->data);
        }
        else
        {
            // cout << subNode->data << endl;
            toplamdugumdeger += subNode->data;
            // cout << "toplamdugumdeger: " << toplamdugumdeger << endl;
        }
        ascii = toplamdugumdeger % (90 - 65 + 1) + 65;
    }
}

int AVL::Height(AVLNode *subNode)
{
    if (subNode == NULL)
        return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}
void AVL::PrintLevel(AVLNode *subNode, int level)
{
    if (subNode == NULL)
        return;
    if (level == 0)
        cout << subNode->data << " ";
    else
    {
        PrintLevel(subNode->left, level - 1);
        PrintLevel(subNode->right, level - 1);
    }
}
bool AVL::Search(AVLNode *subNode, const int &item)
{
    if (subNode == NULL)
        return false;
    if (subNode->data == item)
        return true;
    if (item < subNode->data)
        return Search(subNode->left, item);
    else
        return Search(subNode->right, item);
}

AVL::AVL()
{
    root = NULL;
    stack_real = new Stack();
    stack_temp = new Stack();
    avl_no = 0;
}
bool AVL::isEmpty() const
{
    return root == NULL;
}
void AVL::Add(const int &item)
{
    root = SearchAndAdd(root, item);
}
void AVL::inorder()
{
    inorder(root);
}
void AVL::preorder()
{
    preorder(root);
}
void AVL::postorder()
{
    postorder(root);
}
void AVL::levelorder()
{
    int h = Height();
    for (int level = 0; level <= h; level++)
    {
        PrintLevel(root, level);
    }
}
int AVL::Height()
{
    return Height(root);
}
bool AVL::Search(const int &item)
{
    return Search(root, item);
}
void AVL::SetAvlNo(int avlNo)
{
    avl_no = avlNo;
}
int AVL::getAvlNo()
{
    return avl_no;
}
char AVL::GetAsciiChar()
{
    return static_cast<char>(ascii);
}
int AVL::getStackTop()
{
    return stack_real->top();
}
bool AVL::isEmptyStack()
{
    return stack_real->isEmpty();
}
void AVL::popStack()
{
    stack_temp->push(stack_real->top());
    // cout<<"stack_temp top after pushing stack_real top: "<< stack_temp->top()<<endl;
    stack_real->pop();
    // cout<<"stack_real top after stack_real pop: "<< stack_real->top()<<endl;
}
void AVL::refillStack()
{
    while (!(stack_temp->isEmpty()))
    {
        stack_real->push(stack_temp->top());
        stack_temp->pop();
    }
}
void AVL::Clear()
{
    while (!isEmpty())
        DeleteNode(root);
}
AVL::~AVL()
{
    Clear();
}
