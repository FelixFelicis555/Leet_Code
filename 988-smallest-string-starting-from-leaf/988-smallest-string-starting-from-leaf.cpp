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
    void dfs(TreeNode*root,string s,set<string>&st)
    {
        if(!root)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            s+='a'+root->val;
            reverse(s.begin(),s.end());
            st.insert(s);
            return;
        } 
        s+='a'+root->val;
        dfs(root->left,s,st);
        dfs(root->right,s,st);
        
    }    
    string smallestFromLeaf(TreeNode* root) {
        string s;
        set<string> st;
        dfs(root,s,st);
        return *st.begin();
    }
};