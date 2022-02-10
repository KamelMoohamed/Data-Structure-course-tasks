#include <iostream>
#include "my_tree.h"
using namespace std;

void tree_imp(){
    int size, op;
    cin>>size>>op;
    // Reading the input in a vector
    vector<int> v;
    for (int i=0; i<size;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    auto* tree = new MyTree<int>(v);

    // Looping on Operations
    for (int i=0; i<op;i++){
        int x;
        cin >> x;
        if(x == 1){
            int y;
            cin >> y;
            tree->insert(y);
        }
        else if(x==2){
            int y;
            cin >> y;
            if(tree->search(y)){
                cout << "true\n";
            }else{
                cout << "false\n";
            }
        }else if(x==3){
            int y;
            cin >> y;
            if(y==1){
                tree->inorder_rec();
                cout <<"\n";
            }
            else if(y==2){
                tree->inorder_it();
                cout <<"\n";
            }
        }
        else if(x==4){
            int y;
            cin >> y;
            if(y==1){
                tree->preorder_rec();
                cout <<"\n";
            }
            else if(y==2){
                tree->preorder_it();
                cout <<"\n";
            }
        }
        else if(x==5){
            int y;
            cin >> y;
            if(y==1) {
                tree->postorder_rec();
                cout <<"\n";
            }
            else if(y==2 || y==3){
                tree->postorder_it();
                cout <<"\n";
            }
        }
        else if(x==6){
            tree->breadth_traversal();
            cout <<"\n";
        }
        else if(x==7){
            cout << tree->size();
            cout <<"\n";
        }
    }
};


int main(int argc, char** argv){
    tree_imp();
}