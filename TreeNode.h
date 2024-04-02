#ifndef TREENODE_H
#define TREENODE_H
template <typename T>
class TreeNode {

private:
    TreeNode<T> *left;
    TreeNode<T> *right;
    qreal x;
    qreal y;
public:
    T data;

    TreeNode(const T& item, TreeNode<T> *lptr = nullptr,
             TreeNode<T> *rptr = nullptr){
        this->data = item;
        this->left = lptr;
        this->right = rptr;
        this->x = 0;
        this->y = 0;
    }

    TreeNode<T>* getLeft() const{return left;}
    TreeNode<T>* getRight() const{return right;}
    void setLeft(TreeNode<T>* lptr){left=lptr;}
    void setRight(TreeNode<T>* rptr){right=rptr;}
    qreal getX() const{return x;}
    qreal getY() const{return y;}
    void setX(qreal newX){ x = newX;}
    void setY(qreal newY){ y = newY; }


};

#endif // TREENODE_H
