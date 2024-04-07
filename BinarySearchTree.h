#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include"utilities.h"


template<typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;
    TreeNode<T>* newNode;


    TreeNode<T>* insert(TreeNode<T>* node, const T& value, int x, int y,int pX,int pY,int offset,TreeNode<T>* parent) {
        if (node == nullptr)
        {
            newNode = new TreeNode<T>(value,nullptr,nullptr,x,y,pX,pY,offset);

            if(parent!=nullptr){
                //newNode->setDepth(parent->getDepth()+1);
                newNode->setOffset(parent->getOffest()-50);
            }

            return newNode;
        }

        if (value < node->data)
        {
            node->setLeft(insert(node->getLeft(), value,x-node->getOffest(),y+node->getOffest(),x,y,node->getOffest(),node));
        }
        else if (value > node->data){
            node->setRight(insert(node->getRight(), value, x+node->getOffest(),y+node->getOffest(),x,y,node->getOffest(),node));
        }
        else if(value==node->data){
            utilities::warning();
        }

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
        if (root == nullptr)
            root = insert(root, value, 1000, 1000,1000,1000,300,nullptr);
        else
            root = insert(root, value, root->getX(),root->getY(),0,0,root->getOffest(),root);
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
