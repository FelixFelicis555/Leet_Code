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
    int left_height(TreeNode* node)
    {
        int ht=0;
        while(node!=NULL)
        {
            ht++;
            node=node->left;
        }
        return ht;
    }
    int right_height(TreeNode*node)
    {
        int ht=0;
        while(node!=NULL)
        {
            ht++;
            node=node->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
       if(root==NULL)
            return 0;
        int lh=left_height(root);
        int rh=right_height(root);
        if(lh==rh)
            return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);  
    }
};