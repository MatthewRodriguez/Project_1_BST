//
//  main.cpp
//  a
//
//  Created by Matt Rodriguez on 2/24/20.
//  Copyright © 2020 Matthew Rodriguez. All rights reserved.
//
#include "BST.h"

int main() {

    BST tree;
    Node *newNode = nullptr;

    tree.insertIter(20);
    tree.insertIter(25);
    tree.insertIter(10);
    tree.insertIter(22);
    tree.insertIter(30);
    tree.insertIter(8);
    tree.insertIter(11);
    tree.insertIter(23);
    tree.insertIter(21);
    tree.insertRec(5);
    tree.preOrder();
    cout << endl;
    tree.removeRec(5);
    tree.preOrder();
    cout << endl;
    newNode = tree.findMaxRec();
    cout << "This is the maxRec: " << newNode->info << endl;
    newNode = tree.findMinRec();
    cout << "This is the minRec: " << newNode->info << endl;
    newNode = tree.findMaxIter();
    cout << "This is the maxIter: " << newNode->info << endl;
    newNode = tree.findMinIter();
    cout << "This is the minIter: " << newNode->info << endl;
    newNode = tree.findNextIter(25);
    if (newNode != nullptr)
        cout << "Next: " << newNode->info << endl;
    newNode = tree.findPrevIter(20);
    if (newNode != nullptr)
        cout << "Prev: " << newNode->info << endl;
    return 0;
}

