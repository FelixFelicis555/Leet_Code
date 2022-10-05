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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 1;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty())
        {
            int k=q.size();
            long long start=q.front().second;
            long long end=q.back().second;
            ans=max(ans,end-start+1);
            while(k--)
            {
                auto cur=q.front();
                q.pop();
                long long i=cur.second-start;
                if(cur.first->left)
                   q.push({cur.first->left,(long long)2*i+1});
                if(cur.first->right)
                    q.push({cur.first->right,(long long)2*i+2});
                
            }    
        } 
        return ans;
        
    }
};