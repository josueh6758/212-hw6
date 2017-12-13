#ifndef node_h
#define node_h
#include<iostream>
using namespace std;

template<class T>
   struct Node {
     Node(const T& v) : m_val(v), m_act(true), m_left(0), m_right(0) {}    
     bool is_active(){return m_act;}
     T& get_data(){return m_val;}
     Node<T>* get_left_ptr(){return m_left;}
     Node<T>* get_right_ptr(){return m_right;}
     void set_data(T& entry){m_val=entry;}
     void set_left_link(Node<T>* left){m_left=left;}
     void set_right_link(Node<T>* right){m_right=right;}
     //const members
     const T& get_data() const{return m_val;}
     const  Node<T>* get_left_ptr() const {return m_left;}
     const Node<T>* get_right_ptr() const {return m_right;}
     const bool is_leaf(){return((m_left==0)&&(m_right==0));}	    
     //variables
     T        m_val; 
     bool     m_act;
     Node<T>* m_left;  // pointer to the left subtree. 
     Node<T>* m_right; // pointer to the right subtree.
   };


template<class T>
Node<T>* node_new(T& entry){
/* pre-condition:  i want to create a new node and return a pointer to this node.
   process: 	   return a pointer to a new node.
*/ 
	Node<T>* node_ptr;
	node_ptr = new Node<T>(entry);
	return node_ptr;
}


template<class T, class process>
void node_pre_order(process f, Node<T>* root_ptr){
	if(root_ptr!=0){
	f(root_ptr);
	in_order(f,root_ptr->get_left_ptr());
	in_order(f,root_ptr->get_right_ptr());
	}
}

template<class T, class process>
void node_in_order(process f, Node<T>* root_ptr){
	if(root_ptr!=0){
	in_order(f,root_ptr->get_left_ptr());
	f(root_ptr);
	in_order(f,root_ptr->get_right_ptr());
	}
}

template<class T, class process>
void node_post_order(process f, Node<T>* root_ptr){
	if(root_ptr!=0){
	in_order(f,root_ptr->get_left_ptr());
	in_order(f,root_ptr->get_right_ptr());
	f(root_ptr);
	}
}



#endif
