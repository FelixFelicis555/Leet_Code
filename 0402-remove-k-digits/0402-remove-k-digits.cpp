class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(char c: num){
            while(ans.back()>c && ans.size()>0 && k>0){ // check whether prev-char>cur-char if true then pop it off
                ans.pop_back();
                k--;
            }
            if(ans.size()!=0) // if it's not empty
             ans.push_back(c);
            else if(c!='0') // handle leading-zeros test-case
             ans.push_back(c);
        }
        while(k>0 && ans.size()!=0){ // still we have  chance of removing digits
            ans.pop_back();
            k--;
        }
        return (ans.size()==0)?"0":ans;
    }
};