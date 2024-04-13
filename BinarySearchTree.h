#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include"utilities.h"
#include<QTimer>

template<typename T>
class BinarySearchTree{

private:
    TreeNode<T>* root;
    TreeNode<T>* newNode;


    TreeNode<T>* insert(TreeNode<T>* node, const T& value, int x, int y,int pX,int pY,int offset,TreeNode<T>* parent) {
        if (node == nullptr)
        {
            newNode = new TreeNode<T>(value,nullptr,nullptr,x,y,pX,pY,offset);
            if(parent!=nullptr){
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
            utilities::warningRepeat();
        }

        return node;
    }

    int inorderTraversal(TreeNode<T>* node, int& count,QGraphicsScene* scene) {
        if (node != nullptr) {
            inorderTraversal(node->getLeft(), count, scene);
            if (node->getLeft() != nullptr && node->getRight() != nullptr){
                count++;
                QTimer::singleShot(1000 * count, [=](){
                    utilities::drawSubsidiaries(node->getX(),node->getY(),scene);});
            }
            inorderTraversal(node->getRight(), count,scene);
        }
        return count;
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




    TreeNode<T>* getRoot() const{return root;}
    TreeNode<T>* setRoot(TreeNode<T>* NewRoot){root=NewRoot;}


    void countNodesWithTwoChildren(QGraphicsScene* scene) {
        QString message = "Узлов не найдено";
        int count = 0;
        count = inorderTraversal(root, count,scene);
        if(count!=0)
            message = "Ответ:" + QString::number(count);
        QMessageBox msgBox;
        msgBox.setText(message);
        msgBox.exec();
    }

    void deleteTree(TreeNode<T>* node){
        if(node==nullptr)
            return;
        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }

    void clear(){
        deleteTree(getRoot());
        root = nullptr;
    }

};

#endif // BINARYSEARCHTREE_H
