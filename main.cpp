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
            cur_ptr = head_ptr->get_left_link();
            while(cur_ptr->get_right_link())
            {
                cur_ptr = cur_ptr->get_right_link();
                left_ptr = left_ptr->get_left_link();
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
