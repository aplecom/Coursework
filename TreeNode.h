#ifndef TREENODE_H
#define TREENODE_H
template <typename T>
class TreeNode {

private:
    TreeNode<T> *left;
    TreeNode<T> *right;
    int x, y;
public:
    T data;

    TreeNode(const T& item, TreeNode<T> *lptr = nullptr,
             TreeNode<T> *rptr = nullptr, int x =0, int y =0){
        this->data = item;
        this->left = lptr;
        this->right = rptr;
        this->x = x;
        this->y = y;
    }

    TreeNode<T>* getLeft() const{return left;}
    TreeNode<T>* getRight() const{return right;}
    void setLeft(TreeNode<T>* lptr){left=lptr;}
    void setRight(TreeNode<T>* rptr){right=rptr;}

    int getX(){return x;}
    int getY(){return y;}
    void setX(int newX){x=newX;}
    void setY(int newY){y=newY;}


};

#endif // TREENODE_H
