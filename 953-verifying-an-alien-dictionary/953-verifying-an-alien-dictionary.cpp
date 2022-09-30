class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>m;
        for(int i=0;i<order.size();i++)
            m[order[i]]=i;
        for(int i=1;i<words.size();i++)
        {
            string a=words[i-1],b=words[i];
            for(int j=0;j<a.size();j++)
            {
                if(j==b.size())
                    return false;
                char c=a[j],d=b[j];
                if(m[c]<m[d])
                    break;
                if(m[c]>m[d])
                    return false;
            }    
        }
        return true;
    }
};