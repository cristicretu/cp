#include <iostream>
#include <memory>
#include <stack>

using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode *left_;
    BinaryTreeNode *right_;

    BinaryTreeNode(int value) : value_(value),
                                left_(nullptr),
                                right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode *insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode *insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

int findLargest(const BinaryTreeNode *node)
{
    const BinaryTreeNode *current = node;

    while (current->right_)
    {
        current = current->right_;
    }

    return current->value_;
}

int findSecondLargest(const BinaryTreeNode *rootNode)
{
    // we have 2 possibilites
    // 1. the parent of the "most right" element
    // 2. the largest from the left child's subtree

    const BinaryTreeNode *current = rootNode;

    while (current)
    {
        if (!current->right_->right_ && !current->right_->left_)
        {
            return current->value_;
        }

        if (!current->right_ && current->left_)
        {
            return findLargest(current->left_);
        }

        current = current->right_;
    }

    return 0;
}

int main()
{
    return 0;
}