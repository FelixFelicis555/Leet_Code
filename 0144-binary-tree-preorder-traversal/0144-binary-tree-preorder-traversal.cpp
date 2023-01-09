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
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        stack<TreeNode*>s;
        TreeNode*cur=root;
        while(true)
        {
            while(cur)
            {
                ans.push_back(cur->val);
                s.push(cur);
                cur=cur->left;
            } 
            if(!s.empty())
            {
                cur=s.top();
                s.pop();
                cur=cur->right;
            }
            else
                break;
        } 
        return ans;
    }
};