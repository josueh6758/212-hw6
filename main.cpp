#include<iostream>
//

template<class T>
   struct Node {
     Node(const T& v) : m_val(v), m_act(true), m_left(0), m_right(0) {}    
     T        m_val; 
     bool     m_act;
     Node<T>* m_left;  // pointer to the left subtree. 
     Node<T>* m_right; // pointer to the right subtree.
   };




template<class T>
void new_head(Node<T>* head_ptr){

}


























//End of node
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
     Bag<T> sort() const; // produce a sorted Bag.
   private:
     Node<T>* m_root;  
     long  m_active;   // count of active nodes.
     long  m_inactive; // count of inactive nodes.  
   };





