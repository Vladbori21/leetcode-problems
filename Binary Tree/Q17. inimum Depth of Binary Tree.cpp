~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
  1.Recursively find min depth of left and right nodes
  2.If node is null min=0 we use max otherwise we use min
  3.Return 1 + min
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int leftd = minDepth(root->left);
        int rightd = minDepth(root->right);
        return 1+ (min(leftd, rightd) ? min(leftd, rightd) : max(leftd, rightd));
       
    }
};
