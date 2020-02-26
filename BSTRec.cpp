//
//  BSTRec.cpp
//  a
//
//  Created by Matt Rodriguez on 2/25/20.
//  Copyright © 2020 Matthew Rodriguez. All rights reserved.
//


#include "BST.h"

void BST::insertRec(int item){
    insertRec(item, root);
}

Node* BST::insertRec(int item, Node *n){
    if (n == nullptr){
        n = new Node;
        n->info = item;
        n->left = nullptr;
        n->right = nullptr;
    }
    else if (item < n->info)
        n->left = insertRec(item, n->left);
    else if (item > n->info)
        n->right = insertRec(item, n->right);
    else
        ;
    return n;
}


void BST::removeRec(int item){
    removeRec(item, root);
}

Node* BST::removeRec(int item, Node *n){
    Node *nothing = nullptr;
    if (n == nullptr)
        return nothing;
    if (item < n->info)
        n->left = removeRec(item, n->left);
    else if (item > n->info)
        n->right = removeRec(item, n->right);
    else if (n->left != nullptr && n->right != nullptr){
        n->info = findMinIter(n->right)->info;
        removeRec(n->info, n->right);
    }
    else{
        Node *temp = n;
        n = (n->left != nullptr) ? n->left : n->right;
        delete temp;
    }
    return n;
}

Node* BST::findMaxRec(){
    return  findMaxRec(root);
}

Node* BST::findMaxRec(Node *n){
    if (n != nullptr){
        if (n->right != nullptr)
            n = findMaxRec(n->right);
    }
    return n;
}

Node* BST::findMinRec(){
    return findMinRec(root);
}

Node* BST::findMinRec(Node *n){
    if (n != nullptr){
        if (n->left != nullptr)
            n = findMinRec(n->left);
    }
    return n;
}

Node* BST::findNextRec(int item){
    return findNextRec(item, root);
}

Node* BST::findNextRec(int item, Node *n){
    Node *current = n, *t = n, *nothing = nullptr, *parent = nullptr;
    if (n == nullptr)
        return nothing;
    
    if (current->right != nullptr){
        if (current->info == item){
            if (current->right != nullptr){
                if(current->right->left != nullptr)
                    return current->right->left;
                else
                    return current->right;
            }
            else if (n->right == nullptr){
                if(parent->info > item)
                    return parent;
            }
        }
        else if (current->left->info == item){
            if (current->left->right != nullptr){
                if(current->left->right->left != nullptr)                    return current->left->right->left;
                else
                    return current->left->right;
            }
            else if (current->left->right == nullptr){
                if(current->info > item)
                    return current;
            }
        }
        parent = current;
        current = findNextRec(item, current->right);
    }
    
    if (t->left != nullptr){
        if (t->info == item){
            if (t->right != nullptr){
                if(t->right->left != nullptr)
                    return t->right->left;
                else
                    return t->right;
            }
            else if (n->right == nullptr){
               
                if(parent->info > item)
                    return parent;
            }
        }
        parent = t;
        t = findNextRec(item, t->left);
    }
    return nothing;
}

Node* BST::findPrevRec(int item){
    return findPrevRec(item, root);
}

Node* BST::findPrevRec(int item, Node *n){
    Node *current = n, *t = n, *nothing = nullptr, *parent = nullptr;
    if (n == nullptr)
        return nothing;
    
    //while(current->right != nullptr){
    if (current->right != nullptr){
        if (current->info == item){
            if (current->left != nullptr){
                if(current->left->right != nullptr)
                    return current->left->right;
                else
                    return current->left;
            }
            else if (n->left == nullptr){
                if(parent->info > item)
                    return parent;
            }
        }
        else if (current->left->info == item){
            if (current->left->right != nullptr){
                if(current->left->right->left != nullptr)                    return current->left->right->left;
                else
                    return current->left->right;
            }
            else if (current->left->right == nullptr){
                if(current->info > item)
                    return current;
            }
        }
        parent = current;
        current = findPrevRec(item, current->right);
    }
    
    if (t->left != nullptr){
        if (t->info == item){
            if (t->right != nullptr){
                if(t->right->left != nullptr)
                    return t->right->left;
                else
                    return t->right;
            }
            else if (n->right == nullptr){
               
                if(parent->info > item)
                    return parent;
            }
        }
        parent = t;
        t = findPrevRec(item, t->left);
    }
    return nothing;
}
