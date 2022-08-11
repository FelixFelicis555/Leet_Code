#if a string have occurrences x times, any of its substring must also appear at least x times
#there must be a substring of length minSize, that has the most occurrences
#so that we just need to count the occurrences of all substring with length minSize

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
