#include<iostream>
#include"node.h"
#include"student.h"
#include "BST.hpp"
using namespace std;


int main(){
    //srand(time(NULL));
    //---Intiate tree, add 10 students, print ssn
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
    cout << "tree after insertion: " << endl;
    tree.display();
    
    //----Set head pointer to inactive with remove()
    tree.remove(tree.get_m_root()->get_data(), tree.get_m_root());
    cout << "after calling remove on head node. Only active/inactive  nodes below. head node should be unactive---" << endl;
    //-----Print tree's active and inactive nodes after remove()
    tree.begin();
    tree.display_act_nodes();
    cout << "tree size: " << tree.size() << endl;

    //-----Run compress on tree
    tree.compress(tree.get_m_root());
    cout << "tree after compress-------------" << endl;
    tree.begin();
    tree.display();
    
    
    
    
    
    
    
  
    

//
//    for(int x=0;x<10;++x){
//        Student input;
//        tree.insert(input);
//    }
//    Student find_me;
//    tree.insert(find_me);
//    tree.display();
//    if(tree.is_member(find_me)) cout<<"he in here!\n";
//    else cout<< "he not in here!\n";

}
