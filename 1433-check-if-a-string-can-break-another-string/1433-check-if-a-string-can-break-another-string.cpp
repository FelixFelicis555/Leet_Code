class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
         vector<int> v(26,0);
        bool b1=true, b2=true;
        for(int i=0;i<s1.size();i++)
            v[s1[i]-'a']++;
        for(int i=0;i<s2.size();i++)
            v[s2[i]-'a']--;
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=v[i];
            if(ans<0)
                b1=false;
            if(ans>0)
                b2=false;
            if(!b1 && !b2)
                return false;
        }
        return true;
    }
};