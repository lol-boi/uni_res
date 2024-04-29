#include <iostream>
using namespace std;

class rb_tree{
    private:
        class node{
            public:
            node *parent; 
            int colour; //0 for red and 1 for black 
            int val;
            node *left;
            node *right; 
                node(int v, int colour = 1, node *p = nullptr, node *l = nullptr, node *r = nullptr): parent(p), val(v), colour(colour),left(l),right(r){}        
        };
        node *root;
        node *nil;
    public:
         
        void transplant(node *u, node *v) {
            if (u->parent == nil)
                root = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }
        
        void rb_delete_fixup(node *x) {
            while (x != root && x->colour == 1) {
                if (x == x->parent->left) {
                    node *w = x->parent->right;
                    if (w->colour == 0) {
                        w->colour = 1;
                        x->parent->colour = 0;
                        left_rotate(x->parent);
                        w = x->parent->right;
                    }
                    if (w->left->colour == 1 && w->right->colour == 1) {
                        w->colour = 0;
                        x = x->parent;
                    } else {
                        if (w->right->colour == 1) {
                            w->left->colour = 1;
                            w->colour = 0;
                            right_rotate(w);
                            w = x->parent->right;
                        }
                        w->colour = x->parent->colour;
                        x->parent->colour = 1;
                        w->right->colour = 1;
                        left_rotate(x->parent);
                        x = root;
                    }
                } else {
                    node *w = x->parent->left;
                    if (w->colour == 0) {
                        w->colour = 1;
                        x->parent->colour = 0;
                        right_rotate(x->parent);
                        w = x->parent->left;
                    }
                    if (w->right->colour == 1 && w->left->colour == 1) {
                        w->colour = 0;
                        x = x->parent;
                    } else {
                        if (w->left->colour == 1) {
                            w->right->colour = 1;
                            w->colour = 0;
                            left_rotate(w);
                            w = x->parent->left;
                        }
                        w->colour = x->parent->colour;
                        x->parent->colour = 1;
                        w->left->colour = 1;
                        right_rotate(x->parent);
                        x = root;
                    }
                }
            }
            x->colour = 1;
        }
        
        void rb_delete(node *z) {
            node *y = z;
            node *x;
            int y_original_colour = y->colour;
            if (z->left == nil) {
                x = z->right;
                transplant(z, z->right);
            } else if (z->right == nil) {
                x = z->left;
                transplant(z, z->left);
            } else {
                y = tree_minimum(z->right);
                y_original_colour = y->colour;
                x = y->right;
                if (y->parent == z)
                    x->parent = y;
                else {
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->colour = z->colour;
            }
            if (y_original_colour == 1)
                rb_delete_fixup(x);
            delete z;
        }
        
        node *tree_minimum(node *x) {
            while (x->left != nil)
                x = x->left;
            return x;
        }

        void left_rotate(node *x){
            node *y = x->right;
            x->right  = y->left;
            if(y->left != nil){
                y->left->parent = x;
            }
            y->parent = x->parent;
            if(x->parent == nil){
                root = y;
            }
            else if (x == x->parent->left){
                x->parent->left = y;
            }
            else{
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        void right_rotate(node *y){
            node *x = y->left;
            y->left = x->right;
            if(x->right != nil){
                x->right->parent = y;
            }
            y->parent = x->parent;
            if(y->parent == nil){
                root = x;
            }
            else if(y->parent->left == y){
                y->parent->left = x;
            }
            else{
                y->parent->right = x;
            }
            x->right = y;
            y->parent = x;
        }

        void rb_tree_fixup(node *new_node){
            node *par = new_node->parent; 
            while(par->colour == 0){  
                if(par = par->parent->left){
                    node *y = par->parent->right;
                    if(y->colour == 0){
                        par->colour = 1;
                        y->colour = 1;
                        par->parent->colour = 0;
                        new_node = par->parent;
                    }
                    else{
                        if( new_node == par->right){
                            new_node  = par;
                            left_rotate(new_node);
                        }
                        par->colour = 1;
                        par->parent->colour = 0;
                        right_rotate(par->parent);
                    }
                }else{
                    node *y = par->parent->left;
                    if(y->colour == 0){
                        par->colour = 1;
                        y->colour = 1;
                        par->parent->colour = 0;
                        new_node = par->parent;
                    }else{
                        if(new_node == par->left){
                            new_node = par;
                            right_rotate(new_node);
                        }
                        par->colour = 1;
                        par->parent->colour = 0;
                        left_rotate(new_node);
                    }
                }
            }
            this->root->colour = 1;
        }

        node *search(int value) {
            node *current = root;
            while (current != nil && current->val != value) {
                if (value < current->val)
                    current = current->left;
                else
                    current = current->right;
            }
            return current; // Returns the node if found, or nil if not found
        }

        void insert(int value){
            node *new_node = new node(value, 0,nil,nil,nil); 
            node *x = root;
            node *y = nil;
            while(x != nil){
                y = x;
                if(new_node->val < x->val)
                    x = x->left;    
                else
                    x = x->right;
            }
            new_node->parent = y;
            if( y == nil)
                root = new_node;
            else if(new_node->val < y->val)
                y->left = new_node;
            else 
                y->right = new_node;
            rb_tree_fixup(new_node);
        }

        rb_tree(){
            nil = new node(0);
            root = nil;
        }
        ~rb_tree(){
            delete nil;
            delete root;
        }
    
};




int main (int argc, char *argv[]) {
    rb_tree tree;
    tree.insert(11);
    tree.insert(2);
    tree.insert(14);
    tree.insert(15);
    tree.insert(1);
    tree.insert(7); 
    tree.insert(8);
    tree.insert(5);
    tree.insert(4);
    tree.rb_delete(tree.search(7)); 
    return 0;
}
