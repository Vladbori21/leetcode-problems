~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
  1.Create root with value equal to mid of nums
  2.Recursively create left root with left half of nums
  3.Recursively create right root with right half of nums
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

    TreeNode* insert(vector<int>& nums, int left, int right){
        if(left>right)return nullptr;
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = insert(nums, left, mid-1);
        root->right = insert(nums, mid+1, right);
        return root;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return insert(nums,0, nums.size()-1);
    }
};
