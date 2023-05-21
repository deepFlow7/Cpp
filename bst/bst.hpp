#include <list>
#include <ostream>
#include <iostream>

template <typename T>
class bst
{
    class node
    {
    public :
        T value;
        node *left = nullptr;
        node *right = nullptr;

        node(T value)
        {
            this->value = value;
        }
        ~node()
        {
            if(this != nullptr)
            {
                if(this->right != nullptr)
                {
                    this->right->~node();
                    this->right = nullptr;
                }
                if(this->left != nullptr)
                {
                    this->left->~node();
                    this->left = nullptr;
                }
            }
        }

        void node_insert(node *new_node);
        void node_remove(T value);
        bool node_search(T value);
    };

    node *root = nullptr;
protected :
    bst(node *n);
public :
    bst () {};
    bst (std::initializer_list<T> v);
    bst (const bst &t);
    bst (bst &&t);
    bst& operator = (const bst &w);
    bst& operator = (bst &&w);
    ~bst ();
    void bst_insert(T value);
    void bst_remove(T value);
    bool bst_search(T value);

    friend std::ostream& operator << (std::ostream &wy, const bst &t)
    {
        if(t.root != nullptr)
        {
            if(t.root->left != nullptr)
            {
                bst *l = new bst(t.root->left);
                wy << *l <<", ";
            }
            wy<< t.root->value;
            if(t.root->right != nullptr)
            {
                bst *r = new bst(t.root->right);
                wy << ", " << *r ;
            }
        }
        return wy;
    }
};
