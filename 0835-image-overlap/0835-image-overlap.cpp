class Solution {
public:
    vector<int> flatten(vector<vector<int>>&A)
    {
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(A[i][j]==1)
                    ans.push_back(i*100+j);
            }
        }
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int>a=flatten(img1);
        vector<int>b=flatten(img2);
        unordered_map<int,int>m;
        for(int i:a)
        {
            for(int j:b)
                m[i-j]++;
        }
        int ans=0;
        for(auto p:m)
            ans=max(ans,p.second);
        return ans;
    }
};