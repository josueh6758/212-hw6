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
    for(int i=0; i < 5; i++) {
        tree.remove(tree.get_m_root()->get_data());
    }
     cout << "remove" << endl;
     cout << tree.get().num_ssn() << endl;
    
//    for(int i=0; i < tree.size(); i++) {
//        cout << tree.get().num_ssn() << endl;
//    }
//

//   // BST<Student> tree2;
//    for(int i=0; i < 10; i++) {
//       //cout << node_new(tree.get())->get_data().num_ssn() << endl;
//       //tree2.insert(node_new(tree.get()));
//        cout << tree.get().num_ssn() << endl;
//      // tree2.insert(tree.get());
//        ++tree;
//     // cout << node_new(tree.get())->get_data().num_ssn() << endl;
//    }

    
//    for(int i=0; i < 10; i++) {
//        Student entry;
//        node_new(entry);
//        tree2.insert(entry);
//        //cout << node_new(entry)->get_data().num_ssn() << endl;
//        cout << node_new(entry)->get_data().num_ssn() << endl;
//    }
    

	
//    for(int x=0;x<10;++x){
//        Student input;
//        tree.insert(input);
//    }
//    tree.display();


}
