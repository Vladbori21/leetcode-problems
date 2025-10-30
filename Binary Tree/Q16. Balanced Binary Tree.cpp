~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
  1.If node is null return 0
  2.Recursively find height of left and right nodes
  3.If abs(heightl-heightr) > 1 return -1(node is unbalanced)
  4.If node is already unbalances return -1
  5.Otherwise return max(heightl, heightr) + 1
  6.If final result -1 tree is unbalanced
*/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

    int height(TreeNode* root){
        if(!root) return 0;
        int heightl = height(root->left);
        int heightr = height(root->right);
        if(heightl == -1 || heightr == -1) return -1;
        if(abs(heightl-heightr) > 1)return -1;
        return max(heightl, heightr) + 1;

    }

    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};
