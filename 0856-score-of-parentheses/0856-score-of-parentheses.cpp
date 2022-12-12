class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans=0,x=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='('){
                if(s[i+1]==')')
                    ans+=1<<x;
                x++;
            }
            else
                x--;
        }
        return ans;
    }
};