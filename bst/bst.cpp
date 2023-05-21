#include "bst.hpp"
#include "errors.hpp"

template <typename T>
void bst<T>::node::node_insert(node *new_node)
{
    if(this->value == new_node->value)
        throw InsertingDuplicateException();
    if(this->value < new_node->value)
    {
        if(this->right == nullptr)
            this->right = new_node;
        else
            this->right->node_insert(new_node);
    }
    else if(this->value > new_node->value)
    {
        if(this->left == nullptr)
            this->left = new_node;
        else
            this->left->node_insert(new_node);
    }
}

template <typename T>
void bst<T>::node::node_remove(T value)
{
    if(this->value > value)
    {
        if(this->left == nullptr)
            throw RemovingFromBstException();
        else if(this->left->value == value)
        {
            if(this->left->left == nullptr)
                this->left = this->left->right;
            else if (this->left->right == nullptr)
                this->left = this->left->left;
            else
            {
                node *temp = this->left->left;
                this->left = this->left->right;
                this->left->node_insert(temp);
            }
        }
        else
            this->left->node_remove(value);
        return;
    }

    if(this->right == nullptr)
        throw RemovingFromBstException();
    if(this->right->value == value)
    {
        if(this->right->left == nullptr)
            this->right = this->right->right;
        else if (this->right->right == nullptr)
            this->right = this->right->left;
        else
        {
            node *temp = this->right->left;
            this->right = this->right->right;
            this->right->node_insert(temp);
        }
    }
    else
        this->right->node_remove(value);
}

template <typename T>
bool bst<T>::node::node_search(T value)
{
    if(this->value == value)
        return true;
    if(this->value > value)
    {
        if(this->left != nullptr)
            return (this->left->node_search(value));
        else
            return false;
    }
    if(this->right != nullptr)
        return (this->right->node_search(value));
    return false;
}

template <typename T>
bst<T>::bst (std::initializer_list<T> v)
{
    for (unsigned int i=0; i<v.size(); i++)
        this->bst_insert(*(v.begin()+i));
}

template <typename T>
bst<T>::bst (const bst<T> &t)
{
    if(t.root != nullptr)
    {
        this->bst_insert(t.root->value);
        if(t.root->left != nullptr)
        {
            bst *l = new bst();
            *l = *new bst(t.root->left);
            this->root->left = l->root;
        }
        if(t.root->right != nullptr)
        {
            bst *r = new bst();
            *r = *new bst(t.root->right);
            this->root->right = r->root;
        }
    }
}

template <typename T>
bst<T>::bst (bst &&t)
{
    if(this->root != nullptr)
        this->root->~node();
    this->root = t.root;
    t.root = nullptr;
}

template <typename T>
bst<T>::bst (node *n)
{
    this->root = n;
}

template <typename T>
bst<T>::~bst ()
{
    if(this->root != nullptr)
    {
        if(root->right != nullptr)
        {
            root->right->~node();
            this->root->right = nullptr;
        }
        if(root->left != nullptr)
        {
            root->right->~node();
            this->root->left = nullptr;
        }
        this->root = nullptr;
    }
}

template <typename T>
bst<T>& bst<T>::operator = (const bst<T> &t)
{
    if(this != &t)
    {
        if(this->root != nullptr)
            this->~bst();
        if(t.root != nullptr)
        {
            this->bst_insert(t.root->value);
            if(t.root->left != nullptr)
            {
                bst *l = new bst();
                *l = *new bst(t.root->left);
                this->root->left = l->root;
            }
            if(t.root->right != nullptr)
            {
                bst *r = new bst();
                *r = *new bst(t.root->right);
                this->root->right = r->root;
            }
        }
    }
    return *this;
}

template <typename T>
bst<T>& bst<T>::operator = (bst<T> &&t)
{
    if(this != &t)
    {
        this->~bst();
        this->root = t.root;
        t.root = nullptr;
    }
    return *this;
}

template <typename T>
void bst<T>::bst_insert(T value)
{
    node *new_node = new node(value);
    if(this->root == nullptr)
        this->root = new_node;
    else
        root->node_insert(new_node);
}

template <typename T>
void bst<T>::bst_remove(T value)
{
    if(this->root == nullptr)
        throw RemovingFromBstException();
    if(root->value == value)
    {
        if(root->left == nullptr)
            this->root = this->root->right;
        else if(root->right == nullptr)
            this->root = this->root->left;
        else
        {
            node *temp = this->root->left;
            this->root = this->root->right;
            this->root->node_insert(temp);
        }
    }
    else
        root->node_remove(value);
}

template <typename T>
bool bst<T>::bst_search(T value)
{
    if(this->root == nullptr)
        return false;
    return root->node_search(value);
}

template class bst<int>;
template class bst<std::string>;
