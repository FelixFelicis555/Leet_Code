class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
      int ans=0;
        for(int i=citations.size()-1;i>=0;i--)
        {
            if(citations[i]>=citations.size()-i)
            {
                ans++;
            }
        }
        return ans;
        
    }
};