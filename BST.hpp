//
//  BST.hpp
//  
//
//  Created by Yukkee chang on 12/13/17.
//

#ifndef BST_hpp
#define BST_hpp
#include "main.cpp"

#include <stdio.h>

template<class T>
class BST {
public:
    BST();
    BST(const BST&);
    void operator=(const BST&);
    ~BST();
    
    bool remove(const T&);
    void insert(const T&);
    bool is_member(const T&) const;
    long size() const { return m_active; }
    void compress();  // removed all marked nodes.
    //uncomment after including a bag
    //Bag<T> sort() const; // produce a sorted Bag.
    int compress(Node<T>*);
private:
    Node<T>* m_root;
    long  m_active;   // count of active nodes.
    long  m_inactive; // count of inactive nodes.
    T& get_data_bag() {return m_root->get_data_node();} //get value of the root
    void swap(Node<T>*, Node<T>*);
    int compress(Node<T>*);
};


//-------BST MEMBER FUNCTIONS---------------------------





//----------------------------------------------------------------






#endif /* BST_hpp */
