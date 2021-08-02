#include <iostream>
#include <memory>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

bool isBalanced(const BinaryTreeNode* treeRoot)
{
    // determine if the tree is superbalanced
    if (treeRoot == nullptr)
    {
        return true;
    }
    
    size_t depths[3];
    size_t depthCount = 0;
    
    stack<pair<const BynaryTreeNode*, size_t>> nodes;
    nodes.push({treeRoot, 0});
    
    while (!nodes.empty())
    {
        const BinaryTreeNode* node = nodes.top().first;
        size_t depth = nodes.top().second;
        nodes.pop();
        
        
    }
    return false;
}


















// tests

const lest::test tests[] = {
    {CASE("Full Tree") {
        auto root = make_unique<BinaryTreeNode>(5);
        root->insertLeft(8)->insertLeft(1);
        root->insertRight(6)->insertRight(4);
        root->left_->insertRight(2);
        root->right_->insertLeft(3);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Both leaves at the same depth") {
        auto root = make_unique<BinaryTreeNode>(3);
        root->insertLeft(4)->insertLeft(1);
        root->insertRight(2)->insertRight(9);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Leaf heights differ by one") {
        auto root = make_unique<BinaryTreeNode>(6);
        root->insertLeft(1);
        root->insertRight(0)->insertRight(7);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Leaf heights differ by two") {
        auto root = make_unique<BinaryTreeNode>(6);
        root->insertLeft(1);
        root->insertRight(0)->insertRight(7)->insertRight(8);
        EXPECT(isBalanced(root.get()) == false);
    }},
    {CASE("Three leaves total") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertLeft(5);
        root->insertRight(9)->insertRight(5);
        root->right_->insertLeft(8);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Both subtrees superbalanced") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertLeft(5);
        root->insertRight(9)->insertRight(5);
        root->right_->insertLeft(8)->insertLeft(7);
        EXPECT(isBalanced(root.get()) == false);
    }},
    {CASE("Both subtrees superbalanced two") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertLeft(2)->insertLeft(3);
        root->left_->insertRight(7)->insertRight(8);
        root->insertRight(4)->insertRight(5)->insertRight(6)->insertRight(9);
        EXPECT(isBalanced(root.get()) == false);
    }},
    {CASE("Three leaves at different levels") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertLeft(2)->insertLeft(3)->insertLeft(5);
        root->left_->insertRight(4);
        root->left_->left_->insertRight(6);
        root->insertRight(7)->insertRight(8)->insertRight(9)->insertRight(10);
        EXPECT(isBalanced(root.get()) == false);
    }},
    {CASE("Only one node") {
        auto root = make_unique<BinaryTreeNode>(1);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Linked list tree") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertRight(2)->insertRight(3)->insertRight(4);
        EXPECT(isBalanced(root.get()) == true);
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
