class Solution {
public:
    bool halvesAreAlike(string s) {
       string v="aeiouAEIOU";
        int mid=s.size()/2;
        int ans=0;
        for(int i=0,j=mid;i<mid;i++,j++)
        {
            if(~ v.find(s[i])) ans++;
            if(~ v.find(s[j])) ans--;
            
        } 
        return ans==0;
    }
};