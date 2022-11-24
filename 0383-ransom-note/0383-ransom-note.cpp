class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       int a[26]={},b[26]={};
        for(int i=0;i<ransomNote.size();i++)
            a[ransomNote[i]-'a']++;
        int n=magazine.size();
        for(int i=0;i<n;i++)
            b[magazine[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(a[i]>b[i])
                return false;
        }
        return true;
    }
};