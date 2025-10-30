~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*-----------RECURSIVE SOLUTION-------------
    Comparing left(q) and right(p) subtrees
    1.If to nodes are null- return true
    2.If one of them is null - return false
    3.If they not same - return false
    4.Recursively compare p->left and q->right AND p->right and q->left(order MATTERS)
    
  -----------ITERATIVE SOLUTION-------------
    1.Add to queue left and right subtrees
    2.Use two roots from queue top
    3.Retpeat steps 1-3 from recursive solution
    4.Add to queue root1->left and root2->right AND root1->right and root2->left(order MATTERS)
*/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



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

    //---------recursive solution----------
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool check(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left, root->right);
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //---------iterative solution----------
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool isSymmetric(TreeNode* root) {

        queue<TreeNode*> q;
        TreeNode *curr1,  *curr2;

        if(!root) return true;

        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){

            curr1 = q.front();q.pop();
            curr2 = q.front();q.pop();

            if(!curr1 && !curr2) continue;
            if(!curr1 || !curr2) return false;
            if(curr1->val != curr2->val) return false;

            q.push(curr1->left);
            q.push(curr2->right);

            q.push(curr1->right);
            q.push(curr2->left);

        }
        return true;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
};
