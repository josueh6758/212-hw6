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
     void display();
     bool remove(const T&);
     void insert( T&);
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
void BST<T>::display(){
"This is the tree:\n";
if(m_root==0){ cout<<"empty tree!"<<endl; return;}
node_print(m_root);
}



template<class T>
bool BST<T>::is_member(const T& student) const{
return true;
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



int main(){
	BST<Student> tree;
	
	for(int x=0;x<10;++x){
		Student input;
		tree.insert(input);
	}
	tree.display();

}
