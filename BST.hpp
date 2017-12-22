//
//  BST.hpp
//  
//
//  Created by Yukkee chang on 12/21/17.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include<iostream>
#include"node.h"
#include"student.h"

template<class T>
class BST {
public:
    BST(): m_root(0), m_cursor(0) {}
    BST(const BST&);
    void operator=(const BST&);
    //~BST();
    Node<T>* tree_search(T&);
    void display();
    bool remove(const T&);
    void insert( T&);
    bool is_member(const T&) const;
    long size() const { return m_active; }
    void compress();  // removed all marked nodes.
    //Bag<T> sort() const; // produce a sorted Bag.
    T& get() {return m_cursor->get_data();}
    void operator ++() {m_cursor->get_left_ptr();}
    bool is_member(T&) const;
    
    
private:
    Node<T>* m_root;
    Node<T>* m_cursor;
    long  m_active;   // count of active nodes.
    long  m_inactive; // count of inactive nodes.
};

template<class T>
Node<T>* BST<T>:: tree_search(T& student)
{
    Node<T>* cursor = m_root;
    //int cursor_ssn = cursor.get_data().num_ssn()
    if(student.num_ssn() == cursor->get_data().num_ssn())
    {
        return cursor;
    }
    else if (student.num_ssn() < cursor->get_data().num_ssn())
    {
        Node<T>* cur;
        cur = cur->get_right_link();
        tree_search(cur->get_data());
    }
    else if (student.num_ssn() > cursor->get_data().num_ssn())
    {
        Node<T>* cur;
        cur = cur->get_right_link();
        tree_search(cur->get_data());
    }
    return cursor;
}


template<class T>
bool remove(T& student )
{
    //pre-condition: takes in object pointer by reference
    //post-condition: sets node to unactive
    tree_search(student)->is_active() = false;
}

template<class T>
int compress(Node<T>*  head_ptr)
{
    //CASE 1 - non-existent
    if(!head_ptr) return 0;
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
            Node<T>* left_ptr = head_ptr->get_left_link();
            Node<T>* right_ptr = head_ptr->get_right_link();
            cur_ptr = head_ptr->get_left_link();
            while(cur_ptr->get_right_link())
            {
                cur_ptr = cur_ptr->get_right_link();
                left_ptr = left_ptr->get_left_link();
            }
            //CASE 1.1 - check if right subtree has left child
            if(right_ptr->get_left_link())
            {
                left_ptr->set_right_link(right_ptr->get_left_link());
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
bool BST<T>::is_member(T& student) const{
    Node<T>* cursor = m_root;
    do{
        if(cursor->get_data().num_ssn()==student.num_ssn()) return true;
        
    }while(!(cursor->is_leaf()));
}

template<class T>
void BST<T>::display(){
    "This is the tree:\n";
    if(m_root==0){ cout<<"empty tree!"<<endl; return;}
    node_print(m_root);
}




template<class T>
void BST<T>::insert( T& entry){
    if(m_root==0){
        //means this is an empty tree
        m_root = new Node<T>( entry);
        cout<<"Initiated a Tree!\nHead: "<<m_root->get_data().num_ssn()<<endl;
        ++m_active;
        return;
    }
    Node<T>* cursor = m_root;
    while(!(cursor->is_leaf())){
        
        if(entry.num_ssn() < cursor->get_data().num_ssn() && cursor->get_left_ptr()){
            cursor= cursor->get_left_ptr();
        } else if (entry.num_ssn() > cursor->get_data().num_ssn() && cursor->get_right_ptr()) {
            cursor=cursor->get_right_ptr();
        } else {
            
            if(entry.num_ssn() < cursor->get_data().num_ssn() && !(cursor->get_left_ptr()))
            {
                Node<T>* insert_node = node_new(entry);
                cursor->set_left_link(insert_node);
                ++m_active;
                return;
            }
            if(entry.num_ssn() > cursor->get_data().num_ssn() && !(cursor->get_right_ptr())){
                cursor->set_right_link(node_new(entry));
                ++m_active;
                return;
            }
        }
    }
    //while loop will stop when it reaches the end. then we insert to left or right
    if(entry.num_ssn() < cursor->get_data().num_ssn()) {cursor->set_left_link(node_new(entry));return;}
    if(entry.num_ssn() > cursor->get_data().num_ssn()) {cursor->set_right_link(node_new(entry));return;}
    if(entry.num_ssn() > cursor->get_data().num_ssn()) return;
}






#endif /* BST_hpp */
