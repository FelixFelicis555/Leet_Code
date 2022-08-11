class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char,int>m;
        unordered_map<string,int>mp;
        int i=0,n=s.size();
        int j=0,res=0;
        while(j<n)
        {
            m[s[j]]++;
            if((j-i+1)>minSize)
            {
                if(--m[s[i]]==0)
                {
                  m.erase(s[i]);  
                }
                i++;
            }
            if((j-i+1)==minSize && (j-i+1)<=maxSize && m.size()<=maxLetters)
            {
                string str= s.substr(i,j-i+1);
                mp[str]++;
                res=max(res,mp[str]);
            } 
            j++;
        } 
        return res;
    }
};