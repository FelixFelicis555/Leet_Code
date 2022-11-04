class Solution {
public:
    bool isVowel(char c)
    {
        return string("aeiou").find(tolower(c))!=string::npos;
    }
    string reverseVowels(string s) {
       for(int i=0,j=s.size()-1;i<j;i++,j--)
       {
           while(i<=j && !isVowel(s[i]))i++;
           while(j>=i && !isVowel(s[j]))j--;
           if(i<j)
               swap(s[i],s[j]);
              
       }
        return s;
    }
};