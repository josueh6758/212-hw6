#include<iostream>
#include"node.h"
#include"student.h"
using namespace std;

template<class T>
   class BST {
   public:
     BST(): m_root(0) {}
     BST(const BST&);
     void operator=(const BST&);
     //~BST();

     bool remove(const T&);
     void insert(const T&);
     bool is_member(const T&) const;
     long size() const { return m_active; }
     void compress();  // removed all marked nodes.
     //Bag<T> sort() const; // produce a sorted Bag.

   private:
     Node<T>* m_root;
     long  m_active;   // count of active nodes.
     long  m_inactive; // count of inactive nodes.  
       };


template<class T>
bool BST<T>::is_member(const T& student) const{
	Node<T>* cursor = m_root;
	do{
	if(cursor->get_data().num_ssn()==student.num_ssn()) return true;
		
	}while(!(cursor->is_leaf()));
}



template<class T>
void BST<T>::insert(const T& entry){
	if(m_root==0){
		//means this is an empty tree 
		m_root = new Node<T>( entry);
		cout<<"Initiated a Tree!\n";
		++m_active;
		return;
	}	
	Node<T>* cursor = m_root;
	bool at_end = false;
	while(!(cursor->is_leaf())){
	
		if(entry.num_ssn() < cursor->get_data().num_ssn() && cursor->get_left_ptr()){
		 cursor=cursor->get_left_ptr(); 	
		} else if (entry.num_ssn() > cursor->num_ssn() && cursor->get_right_ptr()) {
		 cursor=cursor->get_right_ptr();
		} else {	
	
		if(entry.num_ssn() < cursor->get_data().num_ssn() && !(cursor->get_left_ptr()))
		{
				cursor->set_left_ptr(node_new(entry));
				++m_active;
				return;
				}
		if(entry.num_ssn() > cursor->get_data().num_ssn() && !(cursor->get_right_ptr())){
				cursor->set_right_ptr(node_new(entry));
				++m_active;
				return;
				}
		}
	}
	//while loop will stop when it reaches the end. then we insert to left or right
	if(entry.num_ssn() < cursor->get_data().num_ssn()) {cursor->set_left_link();return;}
	if(entry.num_ssn() > cursor->get_data().num_ssn()) {cursor->set_right_link();return;}
	if(entry.num_ssn() > cursor->get_data().num_ssn()) return;
}



int main(){
	BST<Student> tree;

}
