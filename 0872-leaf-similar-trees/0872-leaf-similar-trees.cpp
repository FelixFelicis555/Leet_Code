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
    void g(TreeNode*root,vector<int>&v)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
         }
        g(root->left,v);
        g(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        g(root1,v1);
        g(root2,v2);
        if(v1.size()!=v2.size())
            return false;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
                return false;
        }
        return true;
    }
};