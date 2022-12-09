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
    TreeNode*dfs(TreeNode*root,int cur,int depth)
    {
        if(!root)
            return NULL;
        if(cur==depth)
            return root;
        
        TreeNode*left=dfs(root->left,cur+1,depth);
        TreeNode*right=dfs(root->right,cur+1,depth);
        
        if(left!=NULL && right!=NULL)
            return root;
        return left?left:right;
        
    }
    int find_depth(TreeNode*root)
    {
        if(!root)
            return 0;
        int left=find_depth(root->left);
        int right=find_depth(root->right);
        return 1+max(left,right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        int depth=find_depth(root)-1;
        return dfs(root,0,depth);
    }
    
};