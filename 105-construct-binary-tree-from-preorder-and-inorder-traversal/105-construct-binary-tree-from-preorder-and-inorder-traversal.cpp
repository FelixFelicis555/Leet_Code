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
    int rootInd=0;
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int s,int e)
    {
        if(s>e)
            return NULL;
        TreeNode* root=new TreeNode(preorder[rootInd]);
        int ind=-1;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==preorder[rootInd])
            {
                ind=i;
                break;
            }    
        }  
        rootInd++;
        root->left=solve(preorder,inorder,s,ind-1);
        root->right=solve(preorder,inorder,ind+1,e);
        return root;
    }    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        return solve(preorder,inorder,0,n-1);
    }
};