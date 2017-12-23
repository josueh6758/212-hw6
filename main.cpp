#include<iostream>
#include"node.h"
#include"student.h"
#include "BST.hpp"
using namespace std;

int main(){
	BST<Student> tree;
    cout << "tree size before insertion: " << tree.size() << endl;
    for(int i=0; i < 10; i++) {
        Student entry;
        tree.insert(entry);
        cout << entry.num_ssn() << endl;
    }
    
    //---Print tree after insertion
    tree.begin();
    cout << "tree size before remove: " << tree.size() << endl;
    tree.display();
    
    //----Set head pointer to inactive with remove()
    tree.remove(tree.get_m_root()->get_data());
     cout << "remove------" << endl;
    //-----Print tree's active and inactive nodes after remove()
     tree.begin();
    cout << "tree size: " << tree.size() << endl;
    //check if head ptr, which has gone through remove() to be set is inactive, to be active or inactive
  //  cout << "student node, either act or in-act: " << tree.get_m_root()->m_act() << endl;
    
    //-----display only active nodes in the tree
    tree.display_act();
    cout << "---------" << endl;
    //-----display only inactive nodes in the tree
    tree.display_inact();
   

    
    //-------Todo: run compress on tree
    

}
