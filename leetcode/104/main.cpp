/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
       // split into two, ans = max(left, right) + 1
       int ans = 0;
       if (root != NULL) {
         int maxLeft = maxDepth(root->left);
         int maxRight = maxDepth(root->right);

         ans = max(maxLeft, maxRight) + 1;
       } 

       return ans;
    }
};
