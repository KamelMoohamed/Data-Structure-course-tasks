#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <assert.h>

using namespace std;

template <class T>
struct node{
    T item;
    node *right;
    node *left;
};


template <class T>
class MyTree{
private:
    node<T> *root;
    vector<T> output;

    void in_rec(node<T>* curr){
        if(curr != NULL){
            in_rec(curr->left);
            output.push_back(curr->item);
            in_rec(curr->right);
        }
    }

    void pre_rec(node<T>* curr){
        if(curr != NULL){
            output.push_back(curr->item);
            pre_rec(curr->left);
            pre_rec(curr->right);
        }
    }

    void post_order(node<T>* curr){
        if(curr != NULL){
            post_order(curr->left);
            post_order(curr->right);
            output.push_back(curr->item);
        }
    }

    // New Size function with a node argument to use rec
    int nodeCount(node<T> *p)
    {
        if(p == NULL)
            return 0;
        else
            return 1 + nodeCount(p->left) + nodeCount(p->right);
    }

public:
    /*
     * Constructors
     */
    MyTree(){
        root = NULL;
    };
    MyTree(vector<T> elements){
        root =NULL;
        sort(elements.begin(),elements.end());
        root = insertVector(elements ,0 ,elements.size()-1);
    }
    /*
     * Methods
     */
    bool search(T key){
        node<T> *curr = root;
        while(curr != NULL)
        {
            if(curr->item == key)
                return true;
            else if(curr->item > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return false;
    };

    void insert(T key){
        // Creating Nodes to search with
        node<T>* curr;
        node<T>* secondCurr;

        // Creating New Node
        node<T> *newNode = new node<T>;
        assert(newNode != NULL);
        newNode->item = key;
        newNode->right = NULL;
        newNode->left = NULL;

        // Insert the node
        if(root == NULL)
            root = newNode;
        else{
            curr = root;
            while(curr != NULL){
                secondCurr = curr;
                if(curr->item > key)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
            if(secondCurr->item > key)
                secondCurr->left = newNode;
            else
                secondCurr->right = newNode;
        }
    };

    void inorder_rec(){
        output.clear();
        in_rec(root);
        for(int i=0; i<output.size()-1 ;i++){
            cout << output[i] << " ";
        }
        cout << output[output.size()-1];
    };

    void preorder_rec(){
        output.clear();
        pre_rec(root);
        for(int i=0; i<output.size()-1 ;i++){
            cout << output[i] << " ";
        }
        cout << output[output.size()-1];
    };

    void postorder_rec(){
        output.clear();
        post_order(root);
        for(int i=0; i<output.size()-1 ;i++){
            cout << output[i] << " ";
        }
        cout << output[output.size()-1];
    };

    void inorder_it(){
        output.clear();
        stack<node<T> *> s;
        node<T> *curr = root;

        while (curr != NULL || s.empty() == false) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();

            output.push_back(curr->item);
            curr = curr->right;
        }
        for(int i=0; i<output.size()-1 ;i++){
            cout << output[i] << " ";
        }
        cout << output[output.size()-1];
    }

    void preorder_it(){
        output.clear();
        node<T> *curr = root;
        if (curr == NULL)
            return;

        stack<node<T>*> s;
        s.push(root);
        while(!s.empty()){
            struct node<T>* n = s.top();
            output.push_back(n->item);
            s.pop();

            if (n->right)
                s.push(n->right);
            if (n->left)
                s.push(n->left);
        }
        for(int i=0; i<output.size()-1 ;i++){
            cout << output[i] << " ";
        }
        cout << output[output.size()-1];
    }

    void postorder_it(){
        if (root == NULL)
            return;

        // Create two stacks
        stack<node<T> *> s1, s2;

        // push root to first stack
        s1.push(root);
        node<T>* n;

        // Run while first stack is not empty
        while (!s1.empty()) {
            // Pop an item from s1 and push it to s2
            n = s1.top();
            s1.pop();
            s2.push(n);

            // Push left and right children
            // of removed item to s1
            if (n->left)
                s1.push(n->left);
            if (n->right)
                s1.push(n->right);
        }

        // Print all elements of second stack
        while (!s2.empty()) {
            n = s2.top();
            s2.pop();
            if(s2.empty())
                cout << n->item;
            else
                cout <<n->item << " ";
        }
    }

    void breadth_traversal(){
        output.clear();
        if(root == NULL)
            return;
        else{
            queue<node<T>*> Q;
            Q.push(root);
            while(!Q.empty()){
                node<T>* curr = Q.front();
                Q.pop();
                output.push_back(curr->item);
                if(curr->left != NULL)
                    Q.push(curr->left);
                if(curr->right != NULL)
                    Q.push(curr->right);
            }
            for(int i=0; i<output.size()-1 ;i++){
                cout << output[i] << " ";
            }
            cout << output[output.size()-1];
        }
    };
    int size(){
        return nodeCount(root);
    };

};

#endif