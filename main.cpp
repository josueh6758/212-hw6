#include<iostream>
#include"node.h"
#include"student.h"
#include "BST.hpp"
using namespace std;

int main(){
	BST<Student> tree;
    
    for(int i=0; i < 10; i++) {
        Student entry;
        tree.insert(entry);
       // cout << node_new(entry)->get_data().num_ssn() << endl;
        cout << entry.num_ssn() << endl;
    }
    tree.begin();
    tree.remove(tree.get_m_root()->get_data());
     cout << "remove" << endl;
     tree.begin();
    cout << tree.size() << endl;
//    for(int i=0; i < tree.size(); i++) {
//        cout << "return the rest of the tree" << endl;
//        cout << tree.get().num_ssn() << endl;
//    }
    

}
