/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int k=q.size();
            vector<int>v;
            while(k--)
            {
                Node*cur=q.front();
                q.pop();
                v.push_back(cur->val);
                int n=cur->children.size();
                for(int i=0;i<n;i++)
                {
                    if(cur->children[i]!=NULL)
                    {
                        q.push(cur->children[i]);
                    }    
                }   
            } 
            ans.push_back(v);
        }  
        return ans;
    }
};