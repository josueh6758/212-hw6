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
    // void operator=(const BST&);
    //~BST();
    Node<T>* tree_search(T&);
    void display();
    void display_act_nodes();
    void display_inact_nodes();
    void remove(T&);
    void insert( T&);
    bool is_member(const T&) const;
    //size should return all active and unactive nodes
    int size() { return size_act(); }
    int compress(Node<T>*);  // removed all marked nodes.
    //Bag<T> sort() const; // produce a sorted Bag.
    T& get() {return m_cursor->get_data();}
    //needs to be changed
    void operator ++() {return m_cursor->get_left_ptr();}
    void operator = (Node<T>* m_cursor) {return this->get_ptr() = m_cursor; }
    bool is_member(T&) const;
    void begin() {m_cursor=m_root;}
    
    int size_act() {return m_active;}
    int size_inact() {return m_inactive;}
    Node<T>* get_m_root() {return m_root;}
    Node<T>* get_ptr() {return m_cursor;}
   
    
    
    
private:
    Node<T>* m_root;
    Node<T>* m_cursor;
    int  m_active = 0;   // count of active nodes.
    int m_inactive = 0;  // count of inactive nodes
    
};

template<class T>
Node<T>* BST<T>::tree_search(T& student)
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
        cur = cur->get_right_ptr();
        tree_search(cur->get_data());
    }
    else if (student.num_ssn() > cursor->get_data().num_ssn())
    {
        Node<T>* cur;
        cur = cur->get_right_ptr();
        tree_search(cur->get_data());
    }
    return cursor;
}


template<class T>
void BST<T>::remove(T& student )
{
    //pre-condition: takes in object pointer by reference
    //post-condition: sets node to unactive
    BST<T>::tree_search(student)->is_inactive();
    cout << "student node is suppose to be inactive: " << student.num_ssn() << endl;
    //todo: check to see if student node's m_act is false;
    cout << "m_active: " << m_active << endl;
    m_active = false;
    cout << "m_inactive: " << m_inactive  << endl;
    --m_active;
    ++m_inactive;
    return;
   
}

template<class T>
int BST<T>::compress(Node<T>*  head_ptr)
{
    //CASE 1 - non-existent
    if(!head_ptr) return 0;
    int count = 0;
    count = compress(head_ptr->get_left_ptr());
    count = compress(head_ptr->get_right_ptr());
    
    //CASE 2 - active
    if(head_ptr->m_act)
    {
        count = compress(head_ptr->get_left_ptr());
        count = compress(head_ptr->get_right_ptr());
        count += count;
        return count;
    }
    //CASE 3 - unactive
    else {
        //CASE 1 - Sub-trees exist, go left, hard right
        if(head_ptr->get_right_ptr() && head_ptr->get_left_ptr())
        {
            Node<T>* cur_ptr = head_ptr;
            Node<T>* left_ptr = head_ptr->get_left_ptr();
            Node<T>* right_ptr = head_ptr->get_right_ptr();
            cur_ptr = head_ptr->get_left_ptr();
            while(cur_ptr->get_right_ptr())
            {
                cur_ptr = cur_ptr->get_right_ptr();
                left_ptr = left_ptr->get_left_ptr();
            }
            //CASE 1.1 - check if right subtree has left child
            if(right_ptr->get_left_ptr())
            {
                left_ptr->set_right_link(right_ptr->get_left_ptr());
            }
            
            return ++count;
        }
        //CASE 2 - only left sub-trees
        else if(!head_ptr->get_right_ptr())
        {
            Node<T>* cur_ptr;
            cur_ptr = head_ptr;
            while(cur_ptr->get_left_ptr())
            {
                cur_ptr = cur_ptr->get_left_ptr();
            }
            delete cur_ptr;
            ++count;
            return count;
        }
        //CASE 3 - only right sub-trees
        else if(!(head_ptr->get_left_ptr()))
        {
            Node<T>* cur_ptr;
            cur_ptr = head_ptr;
            while(cur_ptr->get_right_ptr())
            {
                cur_ptr = cur_ptr->get_right_ptr();
            }
            delete cur_ptr;
            ++count;
            return count;
            
        }
        else
        {
            cout << "something is wrong" << endl;
            return 0;
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
    if(m_root->is_active()) {
        cout << "---------display active nodes: " << endl;
        //shouldn't just be m_root
         node_print(m_root);
    } else {
        cout << "---------display inactive nodes: " << endl;
        node_print(m_root);
    }
}

template<class T>
void BST<T>::display_act_nodes(){
    "This is the tree:\n";
    if(m_root==0){ cout<<"empty tree!"<<endl; return;}
    if(m_root->is_active()) {
        cout << "---------display active nodes: " << endl;
        //shouldn't just be m_root
        node_print(m_root);
    } else {
        //case:(!(m_root->is_active()))
        cout << "---------display inactive nodes: " << endl;
        node_print(m_root);
    }
}



template<class T>
void BST<T>::display_inact_nodes(){
    "This is inact nodes:\n";
    if(m_root==0){ cout<<"empty tree!"<<endl; return;}
    if(!(m_root->is_active())) {
        node_print(m_root);
    } else {
        cout << "all act nodes" << endl;
        return;
    }
}





template<class T>
void BST<T>::insert( T& entry){
    if(m_root==0){
        //means this is an empty tree
        m_root = new Node<T>( entry);
        cout<<"Initiated a Tree!\nHead: "<<m_root->get_data().num_ssn()<<endl;
        cout << "m_active: " << m_active << endl;
        ++m_active;
        return;
    }
    Node<T>* cursor = m_root;
    while(!(cursor->is_leaf())){
        //if left and right sub-tree exist
        if(entry.num_ssn() < cursor->get_data().num_ssn() && cursor->get_left_ptr()){
            cursor= cursor->get_left_ptr();
        } else if (entry.num_ssn() > cursor->get_data().num_ssn() && cursor->get_right_ptr()) {
            cursor=cursor->get_right_ptr();
        } else {
            //if left sub-tree DNE, make left subtree
            if(entry.num_ssn() < cursor->get_data().num_ssn() && !(cursor->get_left_ptr()))
            {
                Node<T>* insert_node = node_new(entry);
                cursor->set_left_link(insert_node);
                cout << "m_active: " << m_active << endl;
                ++m_active;
                return;
            }
            //if right sub-tree DNE, make right subtree
            if(entry.num_ssn() > cursor->get_data().num_ssn() && !(cursor->get_right_ptr())){
                cursor->set_right_link(node_new(entry));
                cout << "m_active: " << m_active << endl;
                ++m_active;
                return;
            }
        }
    }
    //while loop will stop when it reaches the end. then we insert to left or right. For the first two cases
    if(entry.num_ssn() < cursor->get_data().num_ssn()) {cursor->set_left_link(node_new(entry));return;}
    if(entry.num_ssn() > cursor->get_data().num_ssn()) {cursor->set_right_link(node_new(entry));return;}
    if(entry.num_ssn() > cursor->get_data().num_ssn()) return;
}






#endif /* BST_hpp */
