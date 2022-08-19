class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>v(26,0);
        vector<bool>vis(26,false);
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++)
            v[s[i]-'a']++;
        for(char c: s)
        {
            v[c-'a']--;
            if(ans.size()==0)
            {
                ans.push_back(c);
                vis[c-'a']=true;
                continue;
            } 
            if(vis[c-'a'])
                continue;
            while(c<ans.back() && ans.size()!=0 &&v[ans.back()-'a']>0)
            {
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }  
            ans.push_back(c);
            vis[c-'a']=true;
        }  
        return ans;
            
    }
};