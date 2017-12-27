#include<iostream>
#include"node.h"
#include"student.h"
using namespace std;

template<class T>
   class BST {
   public:
     BST(): m_root(0),m_active(0),m_inactive(0){}
     BST(const BST&);
     void operator=(const BST&);
     //~BST();
     void display();
     bool remove( T&);
     void insert( T&);
     bool is_member(const T&) const;
     long size() const { return m_active; }
     int compress();  // removed all marked nodes.
     
     //Bag<T> sort() const; // produce a sorted Bag.
     bool operator ==(BST&);
      Node<T>* m_root;

   private:
  //   Node<T>* m_root;
     long  m_active;   // count of active nodes. 
     long  m_inactive; // count of inactive nodes.
     int workit(Node<T>*);  
       };

template<class T>
bool BST<T>::operator ==(BST<T>& tree2){
cout<<"checking for equality!...\n";
if(m_active != tree2.m_active){ 
	cout<<"tree sizes do not match!\n";
	return false;
}
bool equality = true;//this will be true unless my func changes the value of this to false
node_equality(m_root,tree2.m_root,equality);
return equality;

} 

template<class T>
bool BST<T>::remove(T& student)
{
    //pre-condition: takes in object pointer by reference
    //post-condition: sets node to unactive
    if (BST<T>::is_member(student)) {
         cout << "student node is suppose to be inactive: " << student.num_ssn() << endl;
    //TODO: set student's node to inactive:
        Node<T>* ptr = node_search(m_root,student);
	//now check if this is a leaf!!!! 
	if(ptr->is_leaf()){
		
		Node<T>* parent= node_parent(m_root,student);
		if(parent->get_left_ptr()==ptr) parent->set_left_link(0);
		
		if(parent->get_right_ptr()==ptr) parent->set_right_link(0);

		delete ptr;
		//ptr = 0; //set the ptr to 0 now or else parent will link to empty memory	
		--m_active;
		cout<<"that student is a leaf, safely removing!\n";
		return true;
	}
	
	ptr->m_act = false;
        --m_active;
        ++m_inactive;
	 cout << "m_active (# active nodes): " << m_active << endl;
   	 cout << "m_inactive (# inactive nodes): " << m_inactive  << endl;
	return true;
    }
    cout << "m_active (# active nodes): " << m_active << endl;
    cout << "m_inactive (# inactive nodes): " << m_inactive  << endl;
    return false;
   
}


template<class T>
int BST<T>::compress(){
if(!m_root) return 0;
cout<<"compress is taking out the trash!\n\n";
return workit(m_root);

}

template<class T>
int BST<T>::workit(Node<T>*  head_ptr)
{
    //CASE 1 - non-existent
    if(!head_ptr) return 0;
    int count = 0;
    cout<<"Compress is at: "<<head_ptr->get_data().string_ssn()<<endl;
    
	
    //count = compress(head_ptr->get_left_ptr());
    //count = compress(head_ptr->get_right_ptr());
    
    //CASE 2 - active
    //if(head_ptr->m_act)
        //keep calling the recursion until it gets to an unactive node (see case 3)
    
        count += workit(head_ptr->get_left_ptr());
        count += workit(head_ptr->get_right_ptr());
        //count += count;
    
    //CASE 3 - unactive
    if (!(head_ptr->m_act)){
        //CASE 3.1 - Sub-trees exist, go left, hard right
        
        //head_ptr is the one we want to delete/swap data with
        //head_ptr isn't necessarily head of the tree, it's the lowest unactive node 
       cout<<"Compress gonna make do its job on: "<<head_ptr->get_data().string_ssn()<<endl;
	if(head_ptr->get_right_ptr()&&head_ptr->get_left_ptr()) cout<<"this node has both children!\n";
	else if(head_ptr->get_right_ptr()) cout<<"this node only has right child\n";
	else if(head_ptr->get_left_ptr()) cout<<"this node only has left\n";
	else cout<<"this node has no children\n";


	if(head_ptr->get_right_ptr() && head_ptr->get_left_ptr())
        {
            cout << "compress: case 3 - inactive" << endl;
            Node<T>* cur_ptr = head_ptr;
            Node<T>* left_ptr = head_ptr->get_left_ptr();
            Node<T>* right_ptr = head_ptr->get_right_ptr();
            cur_ptr = head_ptr->get_left_ptr();
            
            if(cur_ptr->get_right_ptr()) {
                while(cur_ptr->get_right_ptr())
                {
                    //----move right ptr to the bottom right
                    cur_ptr = cur_ptr->get_right_ptr();
                }
                //----swap data
                head_ptr->get_data() = cur_ptr->get_data();
                delete cur_ptr;
                //re-activate ptr
                head_ptr->m_act = true;
                //---make new cursor pointer to go back to the head
                Node<T>* cur_ptr = head_ptr;
                //----okay something has to happen now
            }
           
//            if(right_ptr->get_left_ptr())
//            {
//                cout << "compress: case 3 cont"  << endl;
//                left_ptr->set_right_link(right_ptr->get_left_ptr());
//            }
            
            ++count;
            cout << "exiting compress case 3"  << endl;
            return count;
        }
        //CASE 3.2 - only left sub-trees
        else if(head_ptr->get_left_ptr())
        {
            cout << "compress: case 3.2- left ST" << endl;
            Node<T>* cur_ptr;
            cur_ptr = head_ptr;
            //move cur down left once, cur will be the new pointer that replaces head
            cur_ptr = cur_ptr->get_left_ptr();
            //swap data, head now has cur data
            head_ptr->get_data() = cur_ptr->get_data();
            //delete cur ptr, extraneous after swap
            delete cur_ptr;
            ++count;
            head_ptr->m_act = true;
            return count;
        }
        //CASE 3.3 - only right sub-trees
        else if(head_ptr->get_left_ptr())
        {
            cout << "compress: case 3.3- right ST" << endl;
            Node<T>* cur_ptr;
            cur_ptr = head_ptr;
            //move cur down right once, cur will be the new pointer that replaces head
            cur_ptr = cur_ptr->get_right_ptr();
            //swap data, head now has cur data
            head_ptr->get_data() = cur_ptr->get_data();
            //delete cur ptr, extraneous after swap
            delete cur_ptr;
            head_ptr->m_act = true;
            ++count;
            cout << "count: " << count << endl;
            return count;
        }
        else
        {
            cout << "compress: something is wrong" << endl;
            return 0;
        }
    }
    cout << "no junk found here!" << endl;
    return count;
}


template<class T>
void BST<T>::display(){
cout<<"\nThis is the tree(inorder):\n";
if(m_root==0){ cout<<"empty tree!"<<endl; return;}
node_print(m_root);
}



template<class T>
bool BST<T>::is_member(const T& student) const{
if(!(node_search(m_root,student))) return false;
return true;
}



template<class T>
void BST<T>::insert( T& entry){
	if(m_root==0){
		//means this is an empty tree 
		m_root = new Node<T>( entry);
		cout<<"Initiated a Tree!\nHead: "<<m_root->get_data().num_ssn()<<endl<<endl;
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
				//cout<<"count going up!\n";
				++m_active;
				return;
				}
		if(entry.num_ssn() > cursor->get_data().num_ssn() && !(cursor->get_right_ptr())){
				cursor->set_right_link(node_new(entry));
				//cout<<"count going up!\n";
				++m_active;
				return;
				}
		}
	}
	//while loop will stop when it reaches the end. then we insert to left or right
	if(entry.num_ssn() < cursor->get_data().num_ssn()) {cursor->set_left_link(node_new(entry));++m_active;return;}
	if(entry.num_ssn() > cursor->get_data().num_ssn()) {cursor->set_right_link(node_new(entry));++m_active;return;}
	//if(entry.num_ssn() > cursor->get_data().num_ssn()) return;

}



int main(){
	BST<Student> tree;
	
	for(int x=0;x<6;++x){
		Student input;
		tree.insert(input);
	}
	Student find_me;
	tree.insert(find_me);
	tree.display();
	if(tree.is_member(find_me)) cout<<"he in here!\n";
	else cout<< "he not in here!\n";
	cout<<find_me.string_ssn()<<" is who will get inactivated!\n";
	tree.remove(find_me);
	tree.display();
  cout<< tree.compress();

}
