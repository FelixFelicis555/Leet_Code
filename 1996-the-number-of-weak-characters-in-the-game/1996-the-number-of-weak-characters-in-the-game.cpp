class Solution {
public:
   static bool cmp(const vector<int>&v1,const vector<int>&v2)
    {
        return v1[0]==v2[0]?v1[1]>v2[1]:v1[0]<v2[0];
    }    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
       int ans=0;
       int len=properties.size();
        sort(properties.begin(),properties.end(),cmp);
        int max_d=properties[len-1][1];
        for(int i=len-2;i>=0;i--)
        {
            if(properties[i][1]<max_d)
            {
                ans++;
            }
            else
                max_d=properties[i][1];
        }  
        return ans;
    }
};