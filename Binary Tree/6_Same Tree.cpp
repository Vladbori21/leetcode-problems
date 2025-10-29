~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
  1.If two nodes are null - return true
  2.If one of them is null - return false
  3.If nodes value not same - return false
  4.Recursively check left subtrees
  5.Recursively check right subtrees
  6.Return AND of logical results in step 4 and 5
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

    bool check(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p && q || !q && p) return false;
        if(p->val != q->val) return false;
        if(!check(p->left, q->left)) return false;
        if(!check(p->right, q->right)) return false;
        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        return check(p, q);
        
    }
};

