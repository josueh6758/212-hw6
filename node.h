#ifndef node_h
#define node_h
#include<iostream>
using namespace std;

template<class T>
   struct Node {
     Node( T& v) : m_val(v), m_act(true), m_left(0), m_right(0) {}    
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

template<class T>
void node_print(Node<T>* root){
	if(root==NULL){cout<<"END"<<endl;return;}
	
	if(root->m_act)cout<< "Im in: "<<root->get_data().num_ssn()<<endl;
	else cout<<"IM DEACTIVATED BUT IM IN:"<< root->get_data().num_ssn()<<endl;
	node_print(root->get_left_ptr());
	
	node_print(root->get_right_ptr());

}



template<class T>
 Node<T>* node_parent(Node<T>* root,const T& student){
Node<T>* cursor=root;
Node<T>* parent=0;

if(cursor->get_data().num_ssn() == student.num_ssn()){ 
	cout<<"that node has no parent\n";
	return parent;}

while(cursor!=0)//keep searching till we fall off the tree
{
	if(cursor->get_data().num_ssn() == student.num_ssn()) return parent;
	if(cursor->get_data().num_ssn() > student.num_ssn()){
		parent=cursor;
		cursor= cursor->get_left_ptr();
		}
	else {	parent=cursor;
		cursor = cursor->get_right_ptr();}

}
return 0;//if we havent found anything then we'll return the 0 pointer aka null

}

template<class T>
 Node<T>* node_search(Node<T>* root,const T& student){
Node<T>* cursor=root;
while(cursor!=0)//keep searching till we fall off the tree
{
	if(cursor->get_data().num_ssn() == student.num_ssn()) return cursor;
	if(cursor->get_data().num_ssn() > student.num_ssn()) cursor= cursor->get_left_ptr();
	else {cursor = cursor->get_right_ptr();}

}
return 0;//if we havent found anything then we'll return the 0 pointer aka null

}


template<class T>
void node_equality(Node<T>* tree_one,Node<T>* tree_two, bool& equality){
	/*this checks if two trees are equal tree one will traverse and tree two is just to
	 * have access to the other tree to search*/
	if(!(node_search(tree_two, tree_one->get_data() ))){
		return(equality=false);
	}
	node_equality(tree_one->get_left_ptr(),tree_two,equality);
	node_equality(tree_one->get_right_ptr(),tree_two,equality);
}


#endif
