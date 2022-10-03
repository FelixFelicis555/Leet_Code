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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int k=q.size();
            int c=0;
            while(k--)
            {
              TreeNode*cur=q.front();
                c+=cur->val;
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                
            } 
            ans=c;
        } 
        return ans;
    }
};