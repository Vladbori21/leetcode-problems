~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
  -------------DFS solution--------
  1.If node is empty - return 0
  2.Recursively find depth of the deepest subtree
  (left, right) + 1
  -------------BFS solution--------
  1.Find size of level and push to queue subtrees
  of all nodes in level
  2. + 1 to depth
  3. repeat steps 1-2 until queue is not empty
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

    //------------DFS--------------
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) +1;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //------------BFS--------------
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int maxDepth(TreeNode* root) {
        
        if(!root) return 0;

        queue<TreeNode*> q;
        int depth=0;

        q.push(root);
        while(!q.empty()){
            depth++;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
        }
        return depth;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

};
