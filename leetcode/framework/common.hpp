#ifndef _COMMON_H_
#define _COMMON_H_
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

ListNode *genList(std::initializer_list<int> vals)
{
  auto dumy_head = new ListNode(0);
  auto p = dumy_head;
  for (auto i = vals.begin(); i != vals.end(); ++i)
  {
    p->next = new ListNode(*i);
    p = p->next;
  }
  return dumy_head->next;
}

bool equalList(ListNode *l1, ListNode *l2)
{
  while (l1 && l2)
  {
    if (l1->val != l2->val)
      return false;
    l1 = l1->next, l2 = l2->next;
  }
  return (l1 || l2) ? false : true;
}

void printList(ListNode *l)
{
  cout << '[';
  while (l)
  {
    cout << l->val << ", ";
    l = l->next;
  }
  cout << ']' << endl;
}

void preorder(TreeNode *root, vector<int> &result)
{
  if (root == nullptr)
    return;
  result.push_back(root->val);
  preorder(root->left, result);
  preorder(root->right, result);
}

void inorder(TreeNode *root, vector<int> &result)
{
  if (root == nullptr)
    return;
  inorder(root->left, result);
  result.push_back(root->val);
  inorder(root->right, result);
}

template <typename T>
inline constexpr typename std::remove_reference<T>::type &make_ref(T &&r) noexcept
{
  using U = typename std::remove_reference<T>::type;
  return static_cast<U &>(r);
}

#endif //_COMMON_H_