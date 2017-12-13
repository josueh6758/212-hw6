#include<iostream>
#include "BST.hpp"

using namespace std;

template<class T>
   struct Node {
     Node(const T& v) : m_val(v), m_act(true), m_left(0), m_right(0) {}    
     T        m_val; 
     bool     m_act;
     Node<T>* m_left;  // pointer to the left subtree. 
     Node<T>* m_right; // pointer to the right subtree.
       Node<T>* head_ptr;
     Node<T>* get_right_link()             { return m_left; }
     Node<T>* get_left_link()             { return m_right; }
     T& get_data_node() { return m_val;}
   };


//-----------------TOOLKIT FUNCTIONS----------------------
template<class T>
void delete_left(Node<T>* head_ptr)
{
    Node<T>* old_ptr;
    old_ptr = head_ptr;
    head_ptr = head_ptr->get_left_link();
    delete old_ptr;
    old_ptr = 0;
    
}

template<class T>
void delete_right(Node<T>* head_ptr)
{
    Node<T>* old_ptr;
    old_ptr = head_ptr;
    head_ptr = head_ptr->get_right_link();
    delete old_ptr;
    old_ptr = 0;
}




template<class T>
int BST<T>::compress(Node<T>*  head_ptr)
{
    //CASE 1 - non-existent
    if(!Node<T>* head_ptr) return 0;
    int count = 0;
    count = compress(head_ptr->get_left_link());
    count = compress(head_ptr->get_right_link());
    
    //CASE 2 - active
    if(*head_ptr->m_act)
    {
        count = compress(head_ptr->get_left_link());
        count = compress(head_ptr->get_right_link());
        count += count;
        return count;
    }
    //CASE 3 - unactive
    else {
        //CASE 1 - Sub-trees exist, go left, hard right
        if(head_ptr->get_right_link() && head_ptr->get_left_link())
        {
            Node<T>* cur_ptr = head_ptr;
            cur_ptr = head_ptr->get_left_link();
            while(cur_ptr->get_right_link())
            {
                cur_ptr = cur_ptr->get_right_link();
            }
            return ++count;
        }
        //CASE 2 - only left sub-trees
        else if(!head_ptr->get_right_link())
        {
            Node<T>* cur_ptr;
            cur_ptr = head_ptr;
            while(cur_ptr->get_left_link())
            {
                cur_ptr = cur_ptr->get_left_link();
            }
            delete_left(head_ptr);
            ++count;
            return count;
        }
        //CASE 3 - only right sub-trees
        else if(!(head_ptr->get_left_link()))
        {
            Node<T>* cur_ptr;
            cur_ptr = head_ptr;
            while(cur_ptr->get_right_link())
            {
                cur_ptr = cur_ptr->get_right_link();
            }
            delete_right(head_ptr);
            ++count;
            return count;
            
        }
        else
        {
            cout << "something is wrong" << endl;
        }
    }
    
}


template<class T>
void new_head(Node<T>* head_ptr)
{

}






//------------------End of node


int main()
{
    return 0;
}


