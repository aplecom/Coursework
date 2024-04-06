#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

template<typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;
    TreeNode<T>* newNode;

    TreeNode<T>* insert(TreeNode<T>* node, const T& value, int x, int y,int pX,int pY) {
        if (node == nullptr)
        {
            newNode = new TreeNode<T>(value,nullptr,nullptr,x,y,pX,pY);
            return newNode;
        }

        if (value < node->data)
            node->setLeft(insert(node->getLeft(), value,x-150,y+150,x,y));
        else if (value > node->data)
            node->setRight(insert(node->getRight(), value, x+150,y+150,x,y));

        return node;
    }

    void inorderTraversal(TreeNode<T>* node, int& count) {
        if (node != nullptr) {
            inorderTraversal(node->getLeft(), count);
            if (node->getLeft() != nullptr && node->getRight() != nullptr)
                count++;
            inorderTraversal(node->getRight(), count);
        }
    }


public:
    BinarySearchTree() {
        this->root = nullptr;
        this->newNode = nullptr;
    }

    TreeNode<int>* insert(const T& value) {
        if (root == nullptr){
            root = insert(root, value, 150, 150,150,150);
        }
        else{
           root = insert(root, value, root->getX(),root->getY(),150,150);
        }
        return newNode;
    }


    int countNodesWithTwoChildren() {
        int count = 0;
        inorderTraversal(root, count);
        return count;
    }


    TreeNode<T>* getRoot() const{return root;}
};

#endif // BINARYSEARCHTREE_H
