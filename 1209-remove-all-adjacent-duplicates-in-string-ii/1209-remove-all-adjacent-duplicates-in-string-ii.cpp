class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty() || s[i]!=st.top().first)
            {
                st.push({s[i],1});
            }
            else
            {
                auto prev=st.top();
                st.pop();
                st.push({prev.first,prev.second+1});
            }
            if(st.top().second==k)
                st.pop();
          
        }
        string ans="";
        while(!st.empty())
        {
            auto cur=st.top();
            st.pop();
            while(cur.second--)
            {
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};