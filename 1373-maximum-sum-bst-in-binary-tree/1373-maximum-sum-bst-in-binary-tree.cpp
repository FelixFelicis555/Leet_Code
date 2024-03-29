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
     int maxans=0;
    
    vector<int> solve(TreeNode* root){
        if(root==NULL)
            return {1, 0, 0, 0}; //isBST, root val, left max, right min
        vector<int> l=solve(root->left);
        vector<int> r=solve(root->right);
        if((l[0]==1 && (root->left==NULL || root->val>l[3])) && (r[0]==1 && (root->right==NULL || root->val<r[2]))){
            int s=root->val+l[1]+r[1];
            maxans=max(maxans,s);
            int mini, maxi;
            if(root->left==NULL)
                mini=root->val;
            else
                mini=l[2];
            if(root->right==NULL)
                maxi=root->val;
            else
                maxi=r[3];
            return {1, s, mini, maxi};
        }
        return {0,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxans;
    }
};