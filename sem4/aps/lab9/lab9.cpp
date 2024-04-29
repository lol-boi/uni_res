#include <cstdio>
#include <functional>
#include <iostream>
using namespace std;

typedef struct node{
//    struct node *parent;
    int val;
    struct node *left;
    struct node *right;
}bst_node;

bst_node *init_node(int v){
    bst_node *new_node = new bst_node;
    new_node->val = v;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(bst_node *head, int value){ 
    bst_node *ptr = head;     
    while(ptr->val != value){
         if(ptr->left != NULL && ptr->val > value){
             ptr = ptr->left;
         } 
         else if (ptr -> right != NULL && ptr->val < value){
             ptr = ptr->right;
         }
         else{
             if(ptr->val > value){
                 ptr->left = init_node(value);
             }
             else{
                 ptr->right = init_node(value); 
             }
         }
    }


}



bst_node *rotate(bst_node *node, int value, char dir){
    bst_node *par = NULL; 
    bst_node *ptr = node;
    while(ptr->val != value){
        par = ptr;
        if(ptr->val > value){
            ptr = ptr->left; 
        } else {
            ptr = ptr->right; 
        }
        if(ptr == NULL) {
            cerr << "Node with value " << value << " not found." << endl;
            return node;
        }
    }
    bst_node *tmp;
    if(par == NULL && dir == 'r' && ptr->left != NULL){
        tmp = ptr->left; 
        ptr->left = tmp->right;
        tmp->right = ptr;
        node = tmp;
    }
    else if(par==NULL && dir == 'l' && ptr->right != NULL){
        tmp = ptr->right; 
        ptr->right = tmp->left;
        tmp->left = ptr;
        node = tmp;
    }
    else{
        if(dir == 'r' && ptr->left != NULL){
            tmp = ptr->left; 
            ptr->left = tmp->right;
            tmp->right = ptr; 
            if(par->left = ptr)
                par->left = tmp;
            else par->right = tmp; 
        }else if(dir == 'l' && ptr->left != NULL){
            tmp = ptr->right;
            ptr->right = tmp->left;
            tmp->left = ptr;
            if(par->left == ptr)
                ptr->left = tmp;
            else ptr->right = tmp;
        }else{
            cout << "NULL Found in child of the ptr";
        }
    }
    cout << endl << tmp->left->val << " " << tmp->right->val  << endl ;
    return node;
}


int main (int argc, char *argv[]) {
    bst_node *head = init_node(10);
    insert(head,8);
    insert(head,4);
    insert(head,9);
    insert(head,20);
    insert(head,15);
    insert(head,11);
    insert(head,18); 
    insert(head,30);
    insert(head,25);
    insert(head,27);
    insert(head,32); 
    cout << "___________" << endl;
    head = rotate(head,15,'r');
    return 0;
}
