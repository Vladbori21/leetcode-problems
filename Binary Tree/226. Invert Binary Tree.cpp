~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
  1.If root is null return null
  2.Change left root & right root
  3.Recursively invert left subtree
  4.Recursively invert right subtree
  5.Return root
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* node = root->left;
        root->left = root->right;
        root->right = node;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};  
