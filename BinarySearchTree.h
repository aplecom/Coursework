#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

template<typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;
    TreeNode<T>* newNode;

    TreeNode<T>* insert(TreeNode<T>* node, const T& value, int parentX, int parentY) {
        if (node == nullptr)
        {
            newNode = new TreeNode<T>(value,nullptr,nullptr,parentX,parentY);
            return newNode;
        }

        if (value < node->data)
            node->setLeft(insert(node->getLeft(), value,parentX-100,parentY+100));
        else if (value > node->data)
            node->setRight(insert(node->getRight(), value, parentX+100,parentY+100));

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
           root = insert(root, value, 100, 100);
        }
        else{
            root = insert(root, value, root->getX(),root->getY());
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
