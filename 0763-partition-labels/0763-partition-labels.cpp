class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int>l(26,0);
        for(int i=0;i<s.size();i++)
        {
            l[s[i]-'a']=i;
        }
        int start=0,e=0;
        for(int i=0;i<s.size();i++)
        {
            e=max(e,l[s[i]-'a']);
            if(i==e)
            {
                ans.push_back(i-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};