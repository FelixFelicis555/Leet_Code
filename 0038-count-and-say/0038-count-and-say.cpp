class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string prev=countAndSay(n-1),res;
        char ch=prev[0];
        int count=1;
        for(int i=1;i<prev.size();i++)
        {
            if(ch==prev[i])
                count++;
            else
            {
                res+=to_string(count)+ch;
                ch=prev[i];
                count=1;
            }
        }
        return res+to_string(count)+ch;
    }
};