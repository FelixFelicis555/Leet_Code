class Solution {
public:
    bool isEqual(int i,int j)
    {
        if(i==j || (i>='A' && i<='Z' && j==i+32) ||(j>='A' && j<='Z' && i==j+32))
            return true;
        return false;
    }
    bool check(vector<char>&v)
    {
     int l=0;
        int r=v.size();
        while(l<r)
        {
            if(isEqual(v[l],v[r-1])==false)
                return false;
            l+=1;
            r-=1;
        }
        return true;
    }
    bool isPalindrome(string s) {
        int r=s.size();
        if(r==0)
            return true;
        
        vector<char>v;
        int i=0;
        while(i<r)
        {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
                v.push_back(s[i]);
            i+=1;
        }
        if(check(v))
            return true;
        else
            return false;
    }
};