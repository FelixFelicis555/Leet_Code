class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       map<string,int>m1;
        // To get frequency of each word & no of unique words present in array of string word we are using hash-map
        vector<int>ans;
        // To store the begin-indices of all valid window
        for(int i=0;i<words.size();i++)
        {
            m1[words[i]]++;
        }
        // Since all words are of same size,you can get the size of required window 
        int l=words[0].length();
        int n=l*words.size();
        if(s.size()<n)
            return ans;
        for(int i=0;i<=s.size()-n;i++)
        {
            string t=s.substr(i,n);
            map<string,int>m2;
            int j=0;
            for(;j<t.size();j+=l)
            {
                string v=t.substr(j,l);
                if(m1.find(v)==m1.end())
                break;
                if(m1[v]==m2[v])
                    break;
                m2[v]++;
            }
            if(j==t.size())
                ans.push_back(i);
        }
        return ans;
    }
};