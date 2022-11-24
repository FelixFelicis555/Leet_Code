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
   int solve(TreeNode* root, long long cur, int& targetSum){
        if(!root)
            return 0;
        long long cs=cur+root->val;
        return (targetSum==cs) + solve(root->left,cs,targetSum) + solve(root->right,cs,targetSum);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        return solve(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};